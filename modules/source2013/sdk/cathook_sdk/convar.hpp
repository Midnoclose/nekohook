
/*
 *
 * Sexy boiler plate
 *
 */

#pragma once

#include "../public/tier1/utlstring.h"
#include "../public/tier1/utlvector.h"

#define FCVAR_NONE 0

// Command to ConVars and ConCommands
// ConVar Systems
#define FCVAR_UNREGISTERED \
    (1 << 0)  // If this is set, don't add to linked list, etc.
#define FCVAR_DEVELOPMENTONLY \
    (1 << 1)  // Hidden in released products. Flag is removed automatically if
              // ALLOW_DEVELOPMENT_CVARS is defined.
#define FCVAR_GAMEDLL (1 << 2)    // defined by the game DLL
#define FCVAR_CLIENTDLL (1 << 3)  // defined by the client DLL
#define FCVAR_HIDDEN \
    (1 << 4)  // Hidden. Doesn't appear in find or autocomplete. Like
              // DEVELOPMENTONLY, but can't be compiled out.
// ConVar only
#define FCVAR_PROTECTED \
    (1 << 5)  // It's a server cvar, but we don't send the data since it's a
              // password, etc.  Sends 1 if it's not bland/zero, 0 otherwise as
              // value
#define FCVAR_SPONLY \
    (1 << 6)  // This cvar cannot be changed by clients connected to a
              // multiplayer server.
#define FCVAR_ARCHIVE (1 << 7)   // set to cause it to be saved to vars.rc
#define FCVAR_NOTIFY (1 << 8)    // notifies players when changed
#define FCVAR_USERINFO (1 << 9)  // changes the client's info string
#define FCVAR_CHEAT \
    (1 << 14)  // Only useable in singleplayer / debug / multiplayer & sv_cheats
#define FCVAR_PRINTABLEONLY \
    (1 << 10)  // This cvar's string cannot contain unprintable characters (
               // e.g., used for player name etc ).
#define FCVAR_UNLOGGED \
    (1 << 11)  // If this is a FCVAR_SERVER, don't log changes to the log file /
               // console if we are creating a log
#define FCVAR_NEVER_AS_STRING (1 << 12)  // never try to print that cvar
// It's a ConVar that's shared between the client and the server.
// At signon, the values of all such ConVars are sent from the server to the
// client (skipped for local
//  client, of course )
// If a change is requested it must come from the console (i.e., no remote
// client changes) If a value is changed while a server is active, it's
// replicated to all connected clients
#define FCVAR_REPLICATED \
    (1 << 13)  // server setting enforced on clients, TODO rename to FCAR_SERVER
               // at some time
#define FCVAR_DEMO (1 << 16)  // record this cvar when starting a demo file
#define FCVAR_DONTRECORD (1 << 17)  // don't record these command in demofiles
#define FCVAR_RELOAD_MATERIALS \
    (1 << 20)  // If this cvar changes, it forces a material reload
#define FCVAR_RELOAD_TEXTURES \
    (1 << 21)  // If this cvar changes, if forces a texture reload

#define FCVAR_NOT_CONNECTED \
    (1 << 22)  // cvar cannot be changed by a client that is connected to a
               // server
#define FCVAR_MATERIAL_SYSTEM_THREAD \
    (1 << 23)  // Indicates this cvar is read from the material system thread
#define FCVAR_ARCHIVE_XBOX (1 << 24)  // cvar written to config.cfg on the Xbox
#define FCVAR_ACCESSIBLE_FROM_THREADS \
    (1 << 25)  // used as a debugging tool necessary to check material system
               // thread convars
#define FCVAR_SERVER_CAN_EXECUTE \
    (1                           \
     << 28)  // the server is allowed to execute this command on clients via
             // ClientCommand/NET_StringCmd/CBaseClientState::ProcessStringCmd.
#define FCVAR_SERVER_CANNOT_QUERY \
    (1                            \
     << 29)  // If this is set, then the server is not allowed to query this
             // cvar's value (via IServerPluginHelpers::StartQueryCvarValue).
#define FCVAR_CLIENTCMD_CAN_EXECUTE \
    (1 << 30)  // IVEngineClient::ClientCmd is allowed to execute this command.
               // Note: IVEngineClient::ClientCmd_Unrestricted can run any
               // client command.
#define FCVAR_MATERIAL_THREAD_MASK                    \
    (FCVAR_RELOAD_MATERIALS | FCVAR_RELOAD_TEXTURES | \
     FCVAR_MATERIAL_SYSTEM_THREAD)

class CCommand;
//-----------------------------------------------------------------------------
// Called when a ConCommand needs to execute
//-----------------------------------------------------------------------------
using FnCommandCallbackVoid_t = void (*)(void);
using FnCommandCallback_t = void (*)(const CCommand& command);

constexpr int COMMAND_COMPLETION_MAXITEMS = 64;
constexpr int COMMAND_COMPLETION_ITEM_LENGTH = 64;

// Returns 0 to COMMAND_COMPLETION_MAXITEMS worth of completion strings
using FnCommandCompletionCallback = int (*)(
    const char* partial,
    char commands[COMMAND_COMPLETION_MAXITEMS][COMMAND_COMPLETION_ITEM_LENGTH]);

//-----------------------------------------------------------------------------
// Purpose: The base console invoked command/cvar interface
//-----------------------------------------------------------------------------
class ConCommandBase {
    friend class CCvar;
    friend class ConVar;
    friend class ConCommand;
    friend void ConVar_PublishToVXConsole();
    // FIXME: Remove when ConVar changes are done
    friend class CDefaultCvar;

   public:
    ConCommandBase() {
        m_bRegistered = false;
        m_pszName = NULL;
        m_pszHelpString = NULL;

        m_nFlags = 0;
        m_pNext = NULL;
    }
    ConCommandBase(const char* pName, const char* pHelpString = 0,
                   int flags = 0) {
        CreateBase(pName, pHelpString, flags);
    }
    virtual ~ConCommandBase() {}

    virtual bool IsCommand() const { return true; }

    // Check flag
    virtual bool IsFlagSet(int flag) const {
        return (flag & m_nFlags) ? true : false;
    }
    // Set flag
    virtual void AddFlags(int flags) { m_nFlags |= flags; };

    // Return name of cvar
    virtual const char* GetName() const { return m_pszName; }

    // Return help text for cvar
    virtual const char* GetHelpText() const { return m_pszHelpString; }

    virtual bool IsRegistered(void) const { return m_bRegistered; };

    // Returns the DLL identifier
    virtual void* GetDLLIdentifier() const { return 0; };

   protected:
    virtual void CreateBase(const char* pName, const char* pHelpString = 0,
                            int flags = 0) {
        m_bRegistered = false;
        m_pszName = pName;
        m_pszHelpString = pHelpString ? pHelpString : "";
        m_nFlags = flags;
    }

    // Used internally by OneTimeInit to initialize/shutdown
    virtual void Init(){};

    // Internal copy routine ( uses new operator from correct module )
    char* CopyString(const char* from) {
        int len = strlen(from);
        char* to;

        if (len <= 0) {
            to = new char[1];
            to[0] = 0;
        } else {
            to = new char[len + 1];
            strncpy(to, from, len + 1);
        }
        return to;
    }

   private:
    // Next ConVar in chain, (linked list)
    ConCommandBase* m_pNext;

    // Has the cvar been added to the global list?
    bool m_bRegistered;

    // Static data
    const char* m_pszName;
    const char* m_pszHelpString;

    // ConVar flags
    int m_nFlags;
};

//-----------------------------------------------------------------------------
// Command tokenizer
//-----------------------------------------------------------------------------
class CCommand {
   public:
    int ArgC() const { return m_nArgc; }
    const char** ArgV() const {
        return m_nArgc ? (const char**)m_ppArgv : NULL;
    }
    const char* ArgS() const {
        return m_nArgv0Size ? &m_pArgSBuffer[m_nArgv0Size] : "";
    }  // All args that occur after the 0th arg, in string form
    const char* GetCommandString() const {
        return m_nArgc ? m_pArgSBuffer : "";
    }  // The entire command in string form, including the 0th arg
    const char* operator[](int nIndex) const {
        return Arg(nIndex);
    }                                    // Gets at arguments
    const char* Arg(int nIndex) const {  // Gets at arguments
        if (nIndex < 0 || nIndex >= m_nArgc) return "";
        return m_ppArgv[nIndex];
    }

    static int MaxCommandLength() { return COMMAND_MAX_LENGTH - 1; }

   private:
    static constexpr int COMMAND_MAX_ARGC = 64;
    static constexpr int COMMAND_MAX_LENGTH = 512;

    int m_nArgc;
    int m_nArgv0Size;
    char m_pArgSBuffer[COMMAND_MAX_LENGTH];
    char m_pArgvBuffer[COMMAND_MAX_LENGTH];
    const char* m_ppArgv[COMMAND_MAX_ARGC];
};

// Purpose: The console invoked command
class ConCommand : public ConCommandBase {
    friend class CCvar;

   public:
    ConCommand(const char* pName, FnCommandCallbackVoid_t callback,
               const char* pHelpString = 0, int flags = 0,
               FnCommandCompletionCallback completionFunc = 0) {
        m_fnCommandCallbackV1 = callback;
        m_bUsingNewCommandCallback = false;
        m_bUsingCommandCallbackInterface = false;
        m_fnCompletionCallback =
            completionFunc ? completionFunc
                           : [](const char* partial,
                                char commands[COMMAND_COMPLETION_MAXITEMS]
                                             [COMMAND_COMPLETION_ITEM_LENGTH]) {
                                 return 0;
                             };
        m_bHasCompletionCallback = completionFunc != 0 ? true : false;
        ConCommandBase::CreateBase(pName, pHelpString, flags);
    }
    ConCommand(const char* pName, FnCommandCallback_t callback,
               const char* pHelpString = 0, int flags = 0,
               FnCommandCompletionCallback completionFunc = 0) {
        m_fnCommandCallback = callback;
        m_bUsingNewCommandCallback = true;
        m_fnCompletionCallback =
            completionFunc ? completionFunc
                           : [](const char* partial,
                                char commands[COMMAND_COMPLETION_MAXITEMS]
                                             [COMMAND_COMPLETION_ITEM_LENGTH]) {
                                 return 0;
                             };
        m_bHasCompletionCallback = completionFunc != 0 ? true : false;
        m_bUsingCommandCallbackInterface = false;
        ConCommandBase::CreateBase(pName, pHelpString, flags);
    }

    virtual ~ConCommand() {}
    virtual bool IsCommand() const { return true; }
    virtual int AutoCompleteSuggest(const char* partial,
                                    CUtlVector<CUtlString>& commands) {
        if (!m_fnCompletionCallback) return 0;

        // char
        // rgpchCommands[COMMAND_COMPLETION_MAXITEMS][COMMAND_COMPLETION_ITEM_LENGTH];
        /*int ret = (m_fnCompletionCallback)(partial, rgpchCommands);
        for (int i = 0 ; i < ret; i++) {
                CUtlString str = rgpchCommands[i];
                commands.AddToTail(str);
        }
        return ret;*/
        return 0;
    };
    virtual bool CanAutoComplete() { return m_bHasCompletionCallback; }

    // Invoke the function
    virtual void Dispatch(const CCommand& command) {
        if (m_bUsingNewCommandCallback) {
            if (m_fnCommandCallback) {
                (*m_fnCommandCallback)(command);
                return;
            }
        } else if (m_fnCommandCallbackV1) {
            (*m_fnCommandCallbackV1)();
            return;
        }
        // Command without callback!!!
        // TODO: log with a logger ofc
        // assert(0, "Encountered ConCommand '%s' without a callback!\n",
        // GetName() );
    }

   private:
    // NOTE: To maintain backward compat, we have to be very careful:
    // All public virtual methods must appear in the same order always
    // since engine code will be calling into this code, which *does not match*
    // in the mod code; it's using slightly different, but compatible versions
    // of this class. Also: Be very careful about adding new fields to this
    // class. Those fields will not exist in the version of this class that is
    // instanced in mod code.

    // Call this function when executing the command
    union {
        FnCommandCallbackVoid_t m_fnCommandCallbackV1;
        FnCommandCallback_t m_fnCommandCallback;
    };

    FnCommandCompletionCallback m_fnCompletionCallback = 0;

    // TODO: wtf is this shit
    bool m_bHasCompletionCallback = 1;
    bool m_bUsingNewCommandCallback = 1;
    bool m_bUsingCommandCallbackInterface = false;
};

// A console variable
//-----------------------------------------------------------------------------
// Abstract interface for ConVars
//-----------------------------------------------------------------------------
class IConVar {
   public:
    // Value set
    virtual void SetValue(const char* pValue) = 0;
    virtual void SetValue(float flValue) = 0;
    virtual void SetValue(int nValue) = 0;

    // Return name of command
    virtual const char* GetName(void) const = 0;

    // Accessors.. not as efficient as using GetState()/GetInfo()
    // if you call these methods multiple times on the same IConVar
    virtual bool IsFlagSet(int nFlag) const = 0;
};
using FnChangeCallback_t = void (*)(IConVar* var, const char* pOldValue,
                                    float flOldValue);
class ConVar : public ConCommandBase, public IConVar {
    friend class CCvar;
    friend class ConVarRef;

   public:
    ConVar(const char* pName, const char* pDefaultValue, int flags = 0) {
        Create(pName, pDefaultValue, flags);
    }
    ConVar(const char* pName, const char* pDefaultValue, int flags,
           const char* pHelpString) {
        Create(pName, pDefaultValue, flags, pHelpString);
    }
    ConVar(const char* pName, const char* pDefaultValue, int flags,
           const char* pHelpString, bool bMin, float fMin, bool bMax,
           float fMax) {
        Create(pName, pDefaultValue, flags, pHelpString, bMin, fMin, bMax,
               fMax);
    }
    ConVar(const char* pName, const char* pDefaultValue, int flags,
           const char* pHelpString, FnChangeCallback_t callback) {
        Create(pName, pDefaultValue, flags, pHelpString, false, 0.0, false, 0.0,
               callback);
    }

    ConVar(const char* pName, const char* pDefaultValue, int flags,
           const char* pHelpString, bool bMin, float fMin, bool bMax,
           float fMax, FnChangeCallback_t callback) {
        Create(pName, pDefaultValue, flags, pHelpString, bMin, fMin, bMax, fMax,
               callback);
    }

    virtual ~ConVar() { delete[] m_pszString; }

    virtual bool IsFlagSet(int flag) const {
        return (flag & m_pParent->m_nFlags) ? true : false;
    }
    virtual const char* GetHelpText() const {
        return m_pParent->m_pszHelpString;
    }
    virtual bool IsRegistered() const { return m_pParent->m_bRegistered; }
    virtual const char* GetName() const { return m_pParent->m_pszName; }
    virtual void AddFlags(int flags) { m_pParent->m_nFlags |= flags; }
    virtual bool IsCommand() const { return false; }

    // Install a change callback (there shouldn't already be one....)
    void InstallChangeCallback(FnChangeCallback_t callback) {
        // Assert(!m_pParent->m_fnChangeCallback || !callback);
        m_pParent->m_fnChangeCallback = callback;
        if (m_pParent->m_fnChangeCallback)  // Call it immediately to set the
                                            // initial value...
            m_pParent->m_fnChangeCallback(this, m_pszString, m_fValue);
    }

    // Retrieve value
    inline float GetFloat() const { return m_pParent->m_fValue; }
    inline int GetInt() const { return m_pParent->m_nValue; }
    inline bool GetBool() const { return !!GetInt(); }
    inline char const* GetString() const {
        if (m_nFlags & FCVAR_NEVER_AS_STRING) return "FCVAR_NEVER_AS_STRING";
        return (m_pParent->m_pszString) ? m_pParent->m_pszString : "";
    }

    // These just call into the IConCommandBaseAccessor to check flags and set
    // the var (which ends up calling InternalSetValue).
    virtual void SetValue(const char* value) {
        m_pParent->InternalSetValue(value);
    }
    virtual void SetValue(float value) {
        m_pParent->InternalSetFloatValue(value);
    }
    virtual void SetValue(int value) { m_pParent->InternalSetIntValue(value); }

    // Reset to default value
    void Revert() { m_pParent->SetValue(m_pParent->m_pszDefaultValue); }

    // True if it has a min/max setting
    bool GetMin(float& minVal) const {
        minVal = m_pParent->m_fMinVal;
        return m_pParent->m_bHasMin;
    }
    bool GetMax(float& maxVal) const {
        maxVal = m_pParent->m_fMaxVal;
        return m_pParent->m_bHasMax;
    }
    const char* GetDefault() const { return m_pParent->m_pszDefaultValue; }
    void SetDefault(const char* pszDefault) {
        m_pszDefaultValue = pszDefault ? pszDefault : "";
    }

   private:
    // Called by CCvar when the value of a var is changing.
    virtual void InternalSetValue(const char* in) {
        // Save the old value and get the new one
        float old_value = m_fValue;
        float new_value = in ? atof(in) : 0;

        // Get the changed string
        const char* str = in;
        if (ClampValue(new_value)) {
            char tmp[32];
            snprintf(tmp, sizeof(tmp), "%f", new_value);
            str = tmp;
        }

        // Redetermine value
        this->m_fValue = new_value;
        this->m_nValue = static_cast<int>(new_value);

        if (!(m_nFlags & FCVAR_NEVER_AS_STRING))
            this->ChangeStringValue(str, old_value);
    }
    // For CVARs marked FCVAR_NEVER_AS_STRING
    virtual void InternalSetFloatValue(float new_value) {
        if (new_value == this->m_fValue)  // No need to do anything if its equal
            return;

        this->ClampValue(new_value);  // clamp

        // Redetermine value
        float old_value = this->m_fValue;
        this->m_fValue = new_value;
        this->m_nValue = static_cast<int>(this->m_fValue);

        if (!(m_nFlags & FCVAR_NEVER_AS_STRING)) {
            char tmp[32];
            snprintf(tmp, sizeof(tmp), "%f", m_fValue);
            ChangeStringValue(tmp, old_value);
        }
    }
    virtual void InternalSetIntValue(int new_value) {
        if (new_value == this->m_nValue)  // see above
            return;

        float froat = static_cast<float>(new_value);  // du u rike to froat
        if (this->ClampValue(froat)) {  // My guess is to prevent casting float
                                        // to int while keeping use of the clamp
            new_value = static_cast<int>(froat);
        }

        // Redetermine value
        float old_value = this->m_fValue;
        this->m_fValue = froat;
        this->m_nValue = new_value;

        if (!(m_nFlags & FCVAR_NEVER_AS_STRING)) {
            char tmp[32];
            snprintf(tmp, sizeof(tmp), "%d", this->m_nValue);
            ChangeStringValue(tmp, old_value);
        }
    }

    virtual bool ClampValue(float& value) {
        if (m_bHasMin && (value < m_fMinVal)) {
            value = m_fMinVal;
            return true;
        }
        if (m_bHasMax && (value > m_fMaxVal)) {
            value = m_fMaxVal;
            return true;
        }
        return false;
    }
    virtual void ChangeStringValue(const char* to_set, float old_value) {
        // Save old value
        std::string old_str =
            std::string(this->m_pszString,
                        this->m_StringLength);  // HUNGARIAN NOTATION REEEEEEE
        if (to_set) {
            // Reallocate if needed
            int len = strlen(to_set) + 1;
            if (len > this->m_StringLength) {
                delete[] this->m_pszString;
                this->m_pszString = new char[len];
                this->m_StringLength = len;
            }
            // Copy new value to string
            memcpy(this->m_pszString, to_set, len);
        } else
            *this->m_pszString = 0;

        // If nothing has changed, don't do the callbacks.
        if (old_str != m_pszString)
            // Invoke any necessary callback function
            if (m_fnChangeCallback)
                m_fnChangeCallback(this, old_str.c_str(), old_value);
    }

    virtual void Create(const char* pName, const char* pDefaultValue,
                        int flags = 0, const char* pHelpString = 0,
                        bool bMin = false, float fMin = 0.0, bool bMax = false,
                        float fMax = false, FnChangeCallback_t callback = 0) {
        m_pParent = this;

        // Name should be static data
        SetDefault(pDefaultValue);

        m_StringLength = strlen(m_pszDefaultValue) + 1;
        m_pszString = new char[m_StringLength];
        memcpy(m_pszString, m_pszDefaultValue, m_StringLength);

        m_bHasMin = bMin;
        m_fMinVal = fMin;
        m_bHasMax = bMax;
        m_fMaxVal = fMax;

        m_fnChangeCallback = callback;

        m_fValue = (float)atof(m_pszString);
        m_nValue =
            atoi(m_pszString);  // dont convert from float to int and lose bits

        ConCommandBase::CreateBase(pName, pHelpString, flags);
    }

    // Used internally by OneTimeInit to initialize.
    virtual void Init() { ConCommandBase::Init(); }
    int GetFlags() { return m_pParent->m_nFlags; }

   private:
    // This either points to "this" or it points to the original declaration of
    // a ConVar. This allows ConVars to exist in separate modules, and they all
    // use the first one to be declared. m_pParent->m_pParent must equal
    // m_pParent (ie: m_pParent must be the root, or original, ConVar).
    ConVar* m_pParent;

    // Static data
    const char* m_pszDefaultValue;

    // Value
    // Dynamically allocated
    char* m_pszString;
    int m_StringLength;

    // Values
    float m_fValue;
    int m_nValue;

    // Min/Max values
    bool m_bHasMin;
    float m_fMinVal;
    bool m_bHasMax;
    float m_fMaxVal;

    // Call this function when ConVar changes
    FnChangeCallback_t m_fnChangeCallback;
};
