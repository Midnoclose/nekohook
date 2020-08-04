/*
#############################################################################################
# Killing Floor 2 (1.8787) SDK
# Generated with TheFeckless UE3 SDK Generator v1.4_Beta-Rev.51
#
=========================================================================================
# # File: Core_classes.h #
=========================================================================================
# # Credits: uNrEaL, Tamimego, SystemFiles, R00T88, _silencer, the1domo, K@N@VEL
# Thanks: HOOAH07, lowHertz
# Forums: www.uc-forum.com, www.gamedeception.net
#############################################################################################
*/

#ifdef _MSC_VER
#pragma pack(push, 0x4)
#endif

/*
#
=========================================================================================
# # Constants #
=========================================================================================
#
*/

#define CONST_InvAspectRatio16x9 0.56249
#define CONST_InvAspectRatio5x4 0.8
#define CONST_InvAspectRatio4x3 0.75
#define CONST_AspectRatio16x9 1.77778
#define CONST_AspectRatio5x4 1.25
#define CONST_AspectRatio4x3 1.33333
#define CONST_INDEX_NONE -1
#define CONST_UnrRotToDeg 0.00549316540360483
#define CONST_DegToUnrRot 182.0444
#define CONST_RadToUnrRot 10430.3783504704527
#define CONST_UnrRotToRad 0.00009587379924285
#define CONST_DegToRad 0.017453292519943296
#define CONST_RadToDeg 57.295779513082321600
#define CONST_Pi 3.1415926535897932
#define CONST_MaxInt 0x7fffffff

/*
#
=========================================================================================
# # Enums #
=========================================================================================
#
*/

// Enum Core.Object.EDebugBreakType
/*enum EDebugBreakType
{
        DEBUGGER_NativeOnly                                = 0,
        DEBUGGER_ScriptOnly                                = 1,
        DEBUGGER_Both                                      = 2,
        DEBUGGER_MAX                                       = 3
};*/

// Enum Core.Object.EAutomatedRunResult
/*enum EAutomatedRunResult
{
        ARR_Unknown                                        = 0,
        ARR_OOM                                            = 1,
        ARR_Passed                                         = 2,
        ARR_MAX                                            = 3
};*/

// Enum Core.Object.EAspectRatioAxisConstraint
/*enum EAspectRatioAxisConstraint
{
        AspectRatio_MaintainYFOV                           = 0,
        AspectRatio_MaintainXFOV                           = 1,
        AspectRatio_MajorAxisFOV                           = 2,
        AspectRatio_MAX                                    = 3
};*/

// Enum Core.Object.EInterpCurveMode
/*enum EInterpCurveMode
{
        CIM_Linear                                         = 0,
        CIM_CurveAuto                                      = 1,
        CIM_Constant                                       = 2,
        CIM_CurveUser                                      = 3,
        CIM_CurveBreak                                     = 4,
        CIM_CurveAutoClamped                               = 5,
        CIM_MAX                                            = 6
};*/

// Enum Core.Object.EInterpMethodType
/*enum EInterpMethodType
{
        IMT_UseFixedTangentEvalAndNewAutoTangents          = 0,
        IMT_UseFixedTangentEval                            = 1,
        IMT_UseBrokenTangentEval                           = 2,
        IMT_MAX                                            = 3
};*/

// Enum Core.Object.EAxis
/*enum EAxis
{
        AXIS_NONE                                          = 0,
        AXIS_X                                             = 1,
        AXIS_Y                                             = 2,
        AXIS_BLANK                                         = 3,
        AXIS_Z                                             = 4,
        AXIS_MAX                                           = 5
};*/

// Enum Core.Object.ETickingGroup
/*enum ETickingGroup
{
        TG_PreAsyncWork                                    = 0,
        TG_DuringAsyncWork                                 = 1,
        TG_PostAsyncWork                                   = 2,
        TG_PostPhysicsPreClothWork                         = 3,
        TG_PostUpdateWork                                  = 4,
        TG_EffectsUpdateWork                               = 5,
        TG_MAX                                             = 6
};*/

// Enum Core.Object.EInputEvent
/*enum EInputEvent
{
        IE_Pressed                                         = 0,
        IE_Released                                        = 1,
        IE_Repeat                                          = 2,
        IE_DoubleClick                                     = 3,
        IE_Axis                                            = 4,
        IE_MAX                                             = 5
};*/

// Enum Core.Object.AlphaBlendType
/*enum AlphaBlendType
{
        ABT_Linear                                         = 0,
        ABT_Cubic                                          = 1,
        ABT_Sinusoidal                                     = 2,
        ABT_EaseInOutExponent2                             = 3,
        ABT_EaseInOutExponent3                             = 4,
        ABT_EaseInOutExponent4                             = 5,
        ABT_EaseInOutExponent5                             = 6,
        ABT_MAX                                            = 7
};*/

// Enum Core.DistributionVector.EDistributionVectorLockFlags
/*enum EDistributionVectorLockFlags
{
        EDVLF_None                                         = 0,
        EDVLF_XY                                           = 1,
        EDVLF_XZ                                           = 2,
        EDVLF_YZ                                           = 3,
        EDVLF_XYZ                                          = 4,
        EDVLF_MAX                                          = 5
};*/

// Enum Core.DistributionVector.EDistributionVectorMirrorFlags
/*enum EDistributionVectorMirrorFlags
{
        EDVMF_Same                                         = 0,
        EDVMF_Different                                    = 1,
        EDVMF_Mirror                                       = 2,
        EDVMF_MAX                                          = 3
};*/

/*
#
=========================================================================================
# # Classes #
=========================================================================================
#
*/

// Class Core.Object
// 0x0060
class UObject {
   public:
    struct FPointer VfTableObject;   // 0x0000 (0x0008) [0x0000000000000000]
    struct FPointer HashNext;        // 0x0008 (0x0008) [0x0000000000000000]
    struct FQWord ObjectFlags;       // 0x0010 (0x0008) [0x0000000000000000]
    struct FPointer HashOuterNext;   // 0x0018 (0x0008) [0x0000000000000000]
    struct FPointer StateFrame;      // 0x0020 (0x0008) [0x0000000000000000]
    class UObject* Linker;           // 0x0028 (0x0008) [0x0000000000000000]
    struct FPointer LinkerIndex;     // 0x0030 (0x0008) [0x0000000000000000]
    int ObjectInternalInteger;       // 0x0038 (0x0004) [0x0000000000000000]
    int NetIndex;                    // 0x003C (0x0004) [0x0000000000000000]
    class UObject* Outer;            // 0x0040 (0x0008) [0x0000000000000000]
    struct FName Name;               // 0x0048 (0x0008) [0x0000000000000000]
    class UClass* Class;             // 0x0050 (0x0008) [0x0000000000000000]
    class UObject* ObjectArchetype;  // 0x0058 (0x0008) [0x0000000000000000]

   private:
    static UClass* pClassPointer;

   public:
    static TArray<UObject*>* GObjObjects();

    char* GetName();
    char* GetNameCPP();
    char* GetFullName();

    template <class T>
    static T* FindObject(char* ObjectFullName);
    static UClass* FindClass(char* ClassFullName);

    bool IsA(UClass* pClass);

    static UClass* StaticClass() {
        if (!pClassPointer)
            pClassPointer = (UClass*)UObject::GObjObjects()->Data[2];

        return pClassPointer;
    };

    void ProfNodeEvent();
    void ProfNodeSetDepthThreshold();
    void ProfNodeSetTimeThresholdSeconds();
    void ProfNodeStop();
    void ProfNodeStart();
    void GetStringFromGuid();
    void GetGuidFromString();
    void CreateGuid();
    void IsGuidValid();
    void InvalidateGuid();
    void GetLanguage();
    void GetRandomOptionSumFrequency();
    void GetBuildChangelistNumber();
    void GetEngineVersion();
    void GetSystemTime();
    void TimeStamp();
    void TransformVectorByRotation();
    void GetPackageName();
    void IsPendingKill();
    void ByteToFloat();
    void FloatToByte();
    void UnwindHeading();
    void FindDeltaAngle();
    void GetHeadingAngle();
    void GetAngularDegreesFromRadians();
    void GetAngularFromDotDist();
    void GetAngularDistance();
    void GetDotDistance();
    void PointProjectToPlane();
    void PointDistToPlane();
    void PointDistToSegment();
    void PointDistToLine();
    void GetPerObjectConfigSections();
    void ImportJSON();
    void StaticSaveConfig();
    void SaveConfig();
    void FindObject();
    void DynamicLoadObject();
    void GetEnum();
    void Disable();
    void Enable();
    void eventContinuedState();
    void eventPausedState();
    void eventPoppedState();
    void eventPushedState();
    void eventEndState();
    void eventBeginState();
    void DumpStateStack();
    void PopState();
    void PushState();
    void GetStateName();
    void IsChildState();
    void IsInState();
    void GotoState();
    void IsUTracing();
    void SetUTracing();
    void GetFuncName();
    void DebugBreak();
    void GetScriptTrace();
    void ScriptTrace();
    void ParseLocalizedPropertyPath();
    void Localize();
    void WarnInternal();
    void LogInternal();
    void Subtract_LinearColorLinearColor();
    void Multiply_LinearColorFloat();
    void ColorToLinearColor();
    void MakeLinearColor();
    void LerpColor();
    void MakeColor();
    void Add_ColorColor();
    void Multiply_ColorFloat();
    void Multiply_FloatColor();
    void Subtract_ColorColor();
    void EvalInterpCurveVector2D();
    void EvalInterpCurveVector();
    void EvalInterpCurveFloat();
    void vect2d();
    void GetMappedRangeValue();
    void GetRangePctByValue();
    void GetRangeValueByPct();
    void SubtractEqual_Vector2DVector2D();
    void AddEqual_Vector2DVector2D();
    void DivideEqual_Vector2DFloat();
    void MultiplyEqual_Vector2DFloat();
    void Divide_Vector2DFloat();
    void Multiply_Vector2DFloat();
    void Subtract_Vector2DVector2D();
    void Add_Vector2DVector2D();
    void Subtract_QuatQuat();
    void Add_QuatQuat();
    void QuatSlerp();
    void QuatToRotator();
    void QuatFromRotator();
    void QuatFromAxisAndAngle();
    void QuatFindBetween();
    void QuatRotateVector();
    void QuatInvert();
    void QuatDot();
    void QuatProduct();
    void MatrixGetAxis();
    void MatrixGetOrigin();
    void MatrixGetRotator();
    void MakeRotationMatrix();
    void MakeRotationTranslationMatrix();
    void InverseTransformNormal();
    void TransformNormal();
    void InverseTransformVector();
    void TransformVector();
    void Multiply_MatrixMatrix();
    void NotEqual_NameName();
    void EqualEqual_NameName();
    void IsA();
    void ClassIsChildOf();
    void NotEqual_InterfaceInterface();
    void EqualEqual_InterfaceInterface();
    void NotEqual_ObjectObject();
    void EqualEqual_ObjectObject();
    void PathName();
    void SplitString();
    void ParseStringIntoArray();
    void JoinArray();
    void GetRightMost();
    void Split();
    void Repl();
    void Asc();
    void Chr();
    void Locs();
    void Caps();
    void Right();
    void Left();
    void Mid();
    void InStr();
    void Len();
    void SubtractEqual_StrStr();
    void AtEqual_StrStr();
    void ConcatEqual_StrStr();
    void ComplementEqual_StrStr();
    void NotEqual_StrStr();
    void EqualEqual_StrStr();
    void GreaterEqual_StrStr();
    void LessEqual_StrStr();
    void Greater_StrStr();
    void Less_StrStr();
    void At_StrStr();
    void Concat_StrStr();
    void MakeRotator();
    void SClampRotAxis();
    void ClampRotAxisFromRange();
    void ClampRotAxisFromBase();
    void ClampRotAxis();
    void RSize();
    void RDiff();
    void NormalizeRotAxis();
    void RInterpTo();
    void RTransform();
    void RLerp();
    void Normalize();
    void OrthoRotation();
    void RotRand();
    void GetRotatorAxis();
    void GetUnAxes();
    void GetAxes();
    void ClockwiseFrom_IntInt();
    void SubtractEqual_RotatorRotator();
    void AddEqual_RotatorRotator();
    void Subtract_RotatorRotator();
    void Add_RotatorRotator();
    void DivideEqual_RotatorFloat();
    void MultiplyEqual_RotatorFloat();
    void Divide_RotatorFloat();
    void Multiply_FloatRotator();
    void Multiply_RotatorFloat();
    void NotEqual_RotatorRotator();
    void EqualEqual_RotatorRotator();
    void InCylinder();
    void NoZDot();
    void ClampLength();
    void VInterpTo();
    void IsZero();
    void ProjectOnTo();
    void MirrorVectorByNormal();
    void VRandCone2();
    void VRandCone();
    void VRand();
    void VLerp();
    void Normal2D();
    void Normal();
    void VSizeSq2D();
    void VSizeSq();
    void VSize2D();
    void VSize();
    void SubtractEqual_VectorVector();
    void AddEqual_VectorVector();
    void DivideEqual_VectorFloat();
    void MultiplyEqual_VectorVector();
    void MultiplyEqual_VectorFloat();
    void Cross_VectorVector();
    void Dot_VectorVector();
    void NotEqual_VectorVector();
    void EqualEqual_VectorVector();
    void GreaterGreater_VectorRotator();
    void LessLess_VectorRotator();
    void Subtract_VectorVector();
    void Add_VectorVector();
    void Divide_VectorFloat();
    void Multiply_VectorVector();
    void Multiply_FloatVector();
    void Multiply_VectorFloat();
    void Subtract_PreVector();
    void FInterpConstantTo();
    void FInterpTo();
    void FPctByRange();
    void RandRange();
    void FInterpEaseInOut();
    void FInterpEaseOut();
    void FInterpEaseIn();
    void FCubicInterp();
    void FCeil();
    void FFloor();
    void Round();
    void Lerp();
    void FClamp();
    void FMax();
    void FMin();
    void FRand();
    void Square();
    void Sqrt();
    void Loge();
    void Exp();
    void Atan2();
    void Atan();
    void Tan();
    void Acos();
    void Cos();
    void Asin();
    void Sin();
    void Abs();
    void SubtractEqual_FloatFloat();
    void AddEqual_FloatFloat();
    void DivideEqual_FloatFloat();
    void MultiplyEqual_FloatFloat();
    void NotEqual_FloatFloat();
    void ComplementEqual_FloatFloat();
    void EqualEqual_FloatFloat();
    void GreaterEqual_FloatFloat();
    void LessEqual_FloatFloat();
    void Greater_FloatFloat();
    void Less_FloatFloat();
    void Subtract_FloatFloat();
    void Add_FloatFloat();
    void Percent_FloatFloat();
    void Divide_FloatFloat();
    void Multiply_FloatFloat();
    void MultiplyMultiply_FloatFloat();
    void Subtract_PreFloat();
    void ToHex();
    void Clamp();
    void Max();
    void Min();
    void Rand();
    void SubtractSubtract_Int();
    void AddAdd_Int();
    void SubtractSubtract_PreInt();
    void AddAdd_PreInt();
    void SubtractEqual_IntInt();
    void AddEqual_IntInt();
    void DivideEqual_IntFloat();
    void MultiplyEqual_IntFloat();
    void Or_IntInt();
    void Xor_IntInt();
    void And_IntInt();
    void NotEqual_IntInt();
    void EqualEqual_IntInt();
    void GreaterEqual_IntInt();
    void LessEqual_IntInt();
    void Greater_IntInt();
    void Less_IntInt();
    void GreaterGreaterGreater_IntInt();
    void GreaterGreater_IntInt();
    void LessLess_IntInt();
    void Subtract_IntInt();
    void Add_IntInt();
    void Percent_IntInt();
    void Divide_IntInt();
    void Multiply_IntInt();
    void Subtract_PreInt();
    void Complement_PreInt();
    void SubtractSubtract_Byte();
    void AddAdd_Byte();
    void SubtractSubtract_PreByte();
    void AddAdd_PreByte();
    void SubtractEqual_ByteByte();
    void AddEqual_ByteByte();
    void DivideEqual_ByteByte();
    void MultiplyEqual_ByteFloat();
    void MultiplyEqual_ByteByte();
    void OrOr_BoolBool();
    void XorXor_BoolBool();
    void AndAnd_BoolBool();
    void NotEqual_BoolBool();
    void EqualEqual_BoolBool();
    void Not_PreBool();

    // Virtual Functions
    virtual void VirtualFunction00();   // 0x7FF709117BE0 (0x00)
    virtual void VirtualFunction01();   // 0x918602000007FF7 (0x04)
    virtual void VirtualFunction02();   // 0x7FF709186020 (0x08)
    virtual void VirtualFunction03();   // 0x917C05000007FF7 (0x0C)
    virtual void VirtualFunction04();   // 0x7FF70917C050 (0x10)
    virtual void VirtualFunction05();   // 0x9117BE000007FF7 (0x14)
    virtual void VirtualFunction06();   // 0x7FF709117BE0 (0x18)
    virtual void VirtualFunction07();   // 0x913712000007FF7 (0x1C)
    virtual void VirtualFunction08();   // 0x7FF709137120 (0x20)
    virtual void VirtualFunction09();   // 0x913712000007FF7 (0x24)
    virtual void VirtualFunction10();   // 0x7FF709137120 (0x28)
    virtual void VirtualFunction11();   // 0x91DF65000007FF7 (0x2C)
    virtual void VirtualFunction12();   // 0x7FF7091DF650 (0x30)
    virtual void VirtualFunction13();   // 0x91E57B000007FF7 (0x34)
    virtual void VirtualFunction14();   // 0x7FF7091E57B0 (0x38)
    virtual void VirtualFunction15();   // 0x918AC4000007FF7 (0x3C)
    virtual void VirtualFunction16();   // 0x7FF70918AC40 (0x40)
    virtual void VirtualFunction17();   // 0x91D472000007FF7 (0x44)
    virtual void VirtualFunction18();   // 0x7FF7091D4720 (0x48)
    virtual void VirtualFunction19();   // 0x9117BE000007FF7 (0x4C)
    virtual void VirtualFunction20();   // 0x7FF709117BE0 (0x50)
    virtual void VirtualFunction21();   // 0x91E734000007FF7 (0x54)
    virtual void VirtualFunction22();   // 0x7FF7091E7340 (0x58)
    virtual void VirtualFunction23();   // 0x91822C000007FF7 (0x5C)
    virtual void VirtualFunction24();   // 0x7FF7091822C0 (0x60)
    virtual void VirtualFunction25();   // 0x918E39000007FF7 (0x64)
    virtual void VirtualFunction26();   // 0x7FF70918E390 (0x68)
    virtual void VirtualFunction27();   // 0x91573E000007FF7 (0x6C)
    virtual void VirtualFunction28();   // 0x7FF7091573E0 (0x70)
    virtual void VirtualFunction29();   // 0x913712000007FF7 (0x74)
    virtual void VirtualFunction30();   // 0x7FF709137120 (0x78)
    virtual void VirtualFunction31();   // 0x91E0AD000007FF7 (0x7C)
    virtual void VirtualFunction32();   // 0x7FF7091E0AD0 (0x80)
    virtual void VirtualFunction33();   // 0x91E0BA000007FF7 (0x84)
    virtual void VirtualFunction34();   // 0x7FF7091E0BA0 (0x88)
    virtual void VirtualFunction35();   // 0x91E095000007FF7 (0x8C)
    virtual void VirtualFunction36();   // 0x7FF7091E0950 (0x90)
    virtual void VirtualFunction37();   // 0x91E086000007FF7 (0x94)
    virtual void VirtualFunction38();   // 0x7FF7091E0860 (0x98)
    virtual void VirtualFunction39();   // 0x91D488000007FF7 (0x9C)
    virtual void VirtualFunction40();   // 0x7FF7091D4880 (0xA0)
    virtual void VirtualFunction41();   // 0x91E0BB000007FF7 (0xA4)
    virtual void VirtualFunction42();   // 0x7FF7091E0BB0 (0xA8)
    virtual void VirtualFunction43();   // 0x91E0A9000007FF7 (0xAC)
    virtual void VirtualFunction44();   // 0x7FF7091E0A90 (0xB0)
    virtual void VirtualFunction45();   // 0x913712000007FF7 (0xB4)
    virtual void VirtualFunction46();   // 0x7FF709137120 (0xB8)
    virtual void VirtualFunction47();   // 0x913712000007FF7 (0xBC)
    virtual void VirtualFunction48();   // 0x7FF709137120 (0xC0)
    virtual void VirtualFunction49();   // 0x913712000007FF7 (0xC4)
    virtual void VirtualFunction50();   // 0x7FF709137120 (0xC8)
    virtual void VirtualFunction51();   // 0x91F7AD000007FF7 (0xCC)
    virtual void VirtualFunction52();   // 0x7FF7091F7AD0 (0xD0)
    virtual void VirtualFunction53();   // 0x91E0BB000007FF7 (0xD4)
    virtual void VirtualFunction54();   // 0x7FF7091E0BB0 (0xD8)
    virtual void VirtualFunction55();   // 0x91E0A9000007FF7 (0xDC)
    virtual void VirtualFunction56();   // 0x7FF7091E0A90 (0xE0)
    virtual void VirtualFunction57();   // 0x91E0BB000007FF7 (0xE4)
    virtual void VirtualFunction58();   // 0x7FF7091E0BB0 (0xE8)
    virtual void VirtualFunction59();   // 0x91E0A9000007FF7 (0xEC)
    virtual void VirtualFunction60();   // 0x7FF7091E0A90 (0xF0)
    virtual void VirtualFunction61();   // 0x91D909000007FF7 (0xF4)
    virtual void VirtualFunction62();   // 0x7FF7091D9090 (0xF8)
    virtual void VirtualFunction63();   // 0x91E558000007FF7 (0xFC)
    virtual void VirtualFunction64();   // 0x7FF7091E5580 (0x100)
    virtual void VirtualFunction65();   // 0x91DD83000007FF7 (0x104)
    virtual void VirtualFunction66();   // 0x7FF7091DD830 (0x108)
    virtual void VirtualFunction67();   // 0x913712000007FF7 (0x10C)
    virtual void VirtualFunction68();   // 0x7FF709137120 (0x110)
    virtual void VirtualFunction69();   // 0x918C00000007FF7 (0x114)
    virtual void VirtualFunction70();   // 0x7FF70918C000 (0x118)
    virtual void VirtualFunction71();   // 0x91DC3A000007FF7 (0x11C)
    virtual void VirtualFunction72();   // 0x7FF7091DC3A0 (0x120)
    virtual void VirtualFunction73();   // 0x9117F6000007FF7 (0x124)
    virtual void VirtualFunction74();   // 0x7FF709117F60 (0x128)
    virtual void VirtualFunction75();   // 0x9117FB000007FF7 (0x12C)
    virtual void VirtualFunction76();   // 0x7FF709117FB0 (0x130)
    virtual void VirtualFunction77();   // 0x9117F8000007FF7 (0x134)
    virtual void VirtualFunction78();   // 0x7FF709117F80 (0x138)
    virtual void VirtualFunction79();   // 0xA089F7000007FF7 (0x13C)
    virtual void VirtualFunction80();   // 0x7FF70A089F70 (0x140)
    virtual void VirtualFunction81();   // 0x911525000007FF7 (0x144)
    virtual void VirtualFunction82();   // 0x7FF709115250 (0x148)
    virtual void VirtualFunction83();   // 0xA089F7000007FF7 (0x14C)
    virtual void VirtualFunction84();   // 0x7FF70A089F70 (0x150)
    virtual void VirtualFunction85();   // 0x913712000007FF7 (0x154)
    virtual void VirtualFunction86();   // 0x7FF709137120 (0x158)
    virtual void VirtualFunction87();   // 0x913712000007FF7 (0x15C)
    virtual void VirtualFunction88();   // 0x7FF709137120 (0x160)
    virtual void VirtualFunction89();   // 0x913712000007FF7 (0x164)
    virtual void VirtualFunction90();   // 0x7FF709137120 (0x168)
    virtual void VirtualFunction91();   // 0xA089F7000007FF7 (0x16C)
    virtual void VirtualFunction92();   // 0x7FF70A089F70 (0x170)
    virtual void VirtualFunction93();   // 0x97AB13000007FF7 (0x174)
    virtual void VirtualFunction94();   // 0x7FF7097AB130 (0x178)
    virtual void VirtualFunction95();   // 0x97AB4D000007FF7 (0x17C)
    virtual void VirtualFunction96();   // 0x7FF7097AB4D0 (0x180)
    virtual void VirtualFunction97();   // 0x918D42000007FF7 (0x184)
    virtual void VirtualFunction98();   // 0x7FF70918D420 (0x188)
    virtual void VirtualFunction99();   // 0x918206000007FF7 (0x18C)
    virtual void VirtualFunction100();  // 0x7FF709182060 (0x190)
    virtual void VirtualFunction101();  // 0x913712000007FF7 (0x194)
    virtual void VirtualFunction102();  // 0x7FF709137120 (0x198)
    virtual void VirtualFunction103();  // 0x913712000007FF7 (0x19C)
    virtual void VirtualFunction104();  // 0x7FF709137120 (0x1A0)
    virtual void VirtualFunction105();  // 0x9195FB000007FF7 (0x1A4)
    virtual void VirtualFunction106();  // 0x7FF709195FB0 (0x1A8)
    virtual void VirtualFunction107();  // 0x918383000007FF7 (0x1AC)
    virtual void VirtualFunction108();  // 0x7FF709183830 (0x1B0)
    virtual void VirtualFunction109();  // 0x91D95E000007FF7 (0x1B4)
    virtual void VirtualFunction110();  // 0x7FF7091D95E0 (0x1B8)
    virtual void VirtualFunction111();  // 0xA089F7000007FF7 (0x1BC)
    virtual void VirtualFunction112();  // 0x7FF70A089F70 (0x1C0)
    virtual void VirtualFunction113();  // 0x91DC0C000007FF7 (0x1C4)
    virtual void VirtualFunction114();  // 0x7FF7091DC0C0 (0x1C8)
    virtual void VirtualFunction115();  // 0x91DF5B000007FF7 (0x1CC)
    virtual void VirtualFunction116();  // 0x7FF7091DF5B0 (0x1D0)
    virtual void VirtualFunction117();  // 0x91501D000007FF7 (0x1D4)
    virtual void VirtualFunction118();  // 0x7FF7091501D0 (0x1D8)
    virtual void VirtualFunction119();  // 0x91F772000007FF7 (0x1DC)
    virtual void VirtualFunction120();  // 0x7FF7091F7720 (0x1E0)
    virtual void VirtualFunction121();  // 0xA089F7000007FF7 (0x1E4)
    virtual void VirtualFunction122();  // 0x7FF70A089F70 (0x1E8)
    virtual void VirtualFunction123();  // 0x911528000007FF7 (0x1EC)
    virtual void VirtualFunction124();  // 0x7FF709115280 (0x1F0)
    virtual void VirtualFunction125();  // 0x9117BD000007FF7 (0x1F4)
    virtual void VirtualFunction126();  // 0x7FF709117BD0 (0x1F8)
    virtual void VirtualFunction127();  // 0x91DBF3000007FF7 (0x1FC)
    virtual void VirtualFunction128();  // 0x7FF7091DBF30 (0x200)
    virtual void VirtualFunction129();  // 0x91E6F0000007FF7 (0x204)
    virtual void VirtualFunction130();  // 0x7FF7091E6F00 (0x208)
    virtual void VirtualFunction131();  // 0x917D91000007FF7 (0x20C)
    virtual void VirtualFunction132();  // 0x7FF70917D910 (0x210)
    virtual void VirtualFunction133();  // 0x918B12000007FF7 (0x214)
    virtual void VirtualFunction134();  // 0x7FF70918B120 (0x218)
    virtual void VirtualFunction135();  // 0x918B07000007FF7 (0x21C)
    virtual void VirtualFunction136();  // 0x7FF70918B070 (0x220)
    virtual void VirtualFunction137();  // 0x913712000007FF7 (0x224)
    virtual void VirtualFunction138();  // 0x7FF709137120 (0x228)
    virtual void VirtualFunction139();  // 0xA089F7000007FF7 (0x22C)
    virtual void VirtualFunction140();  // 0x7FF70A089F70 (0x230)
    virtual void VirtualFunction141();  // 0x91DBBA000007FF7 (0x234)
    virtual void VirtualFunction142();  // 0x7FF7091DBBA0 (0x238)
    virtual void VirtualFunction143();  // 0x9185A6000007FF7 (0x23C)
    virtual void VirtualFunction144();  // 0x7FF709185A60 (0x240)
    virtual void VirtualFunction145();  // 0x9185BF000007FF7 (0x244)
    virtual void VirtualFunction146();  // 0x7FF709185BF0 (0x248)
    virtual void VirtualFunction147();  // 0x91E583000007FF7 (0x24C)
    virtual void VirtualFunction148();  // 0x7FF7091E5830 (0x250)
    virtual void VirtualFunction149();  // 0xA089F7000007FF7 (0x254)
    virtual void VirtualFunction150();  // 0x7FF70A089F70 (0x258)
    virtual void VirtualFunction151();  // 0x917CEA000007FF7 (0x25C)
    virtual void VirtualFunction152();  // 0x7FF70917CEA0 (0x260)
    virtual void VirtualFunction153();  // 0x9117BE000007FF7 (0x264)
    virtual void VirtualFunction154();  // 0x7FF709117BE0 (0x268)
    virtual void VirtualFunction155();  // 0x917E7B000007FF7 (0x26C)
    virtual void VirtualFunction156();  // 0x7FF70917E7B0 (0x270)
    virtual void VirtualFunction157();  // 0x9183B7000007FF7 (0x274)
    virtual void VirtualFunction158();  // 0x7FF709183B70 (0x278)
    virtual void VirtualFunction159();  // 0x918801000007FF7 (0x27C)
    virtual void VirtualFunction160();  // 0x7FF709188010 (0x280)
    virtual void VirtualFunction161();  // 0x918F85000007FF7 (0x284)
    virtual void VirtualFunction162();  // 0x7FF70918F850 (0x288)
    virtual void VirtualFunction163();  // 0x91903D000007FF7 (0x28C)
    virtual void VirtualFunction164();  // 0x7FF7091903D0 (0x290)
    virtual void VirtualFunction165();  // 0x918B75000007FF7 (0x294)
    virtual void VirtualFunction166();  // 0x7FF70918B750 (0x298)
    virtual void VirtualFunction167();  // 0x9184B9000007FF7 (0x29C)
    virtual void VirtualFunction168();  // 0x7FF709184B90 (0x2A0)
    virtual void VirtualFunction169();  // 0x00007FF7 (0x2A4)
    virtual void VirtualFunction170();  // 0x00000000 (0x2A8)
    virtual void VirtualFunction171();  // 0x4F005500000000 (0x2AC)
    virtual void VirtualFunction172();  // 0x6A0062004F0055 (0x2B0)
    virtual void VirtualFunction173();  // 0x630065006A0062 (0x2B4)
    virtual void VirtualFunction174();  // 0x3A007400630065 (0x2B8)
    virtual void VirtualFunction175();  // 0x47003A003A0074 (0x2BC)
    virtual void VirtualFunction176();  // 0x7400650047003A (0x2C0)
    virtual void VirtualFunction177();  // 0x6F004300740065 (0x2C4)
    virtual void VirtualFunction178();  // 0x66006E006F0043 (0x2C8)
    virtual void VirtualFunction179();  // 0x6700690066006E (0x2CC)
    virtual void VirtualFunction180();  // 0x61004E00670069 (0x2D0)
    virtual void VirtualFunction181();  // 0x65006D0061004E (0x2D4)
    virtual void VirtualFunction182();  // 0x2900280065006D (0x2D8)
    virtual void VirtualFunction183();  // 0x63002000290028 (0x2DC)
    virtual void VirtualFunction184();  // 0x6C006100630020 (0x2E0)
    virtual void VirtualFunction185();  // 0x65006C006C0061 (0x2E4)
    virtual void VirtualFunction186();  // 0x2000640065006C (0x2E8)
    virtual void VirtualFunction187();  // 0x6E006F00200064 (0x2EC)
    virtual void VirtualFunction188();  // 0x630020006E006F (0x2F0)
    virtual void VirtualFunction189();  // 0x61006C00630020 (0x2F4)
    virtual void VirtualFunction190();  // 0x7300730061006C (0x2F8)
    virtual void VirtualFunction191();  // 0x77002000730073 (0x2FC)
    virtual void VirtualFunction192();  // 0x74006900770020 (0x300)
    virtual void VirtualFunction193();  // 0x20006800740069 (0x304)
    virtual void VirtualFunction194();  // 0x6F006300200068 (0x308)
    virtual void VirtualFunction195();  // 0x66006E006F0063 (0x30C)
    virtual void VirtualFunction196();  // 0x6700690066006E (0x310)
    virtual void VirtualFunction197();  // 0x6E002000670069 (0x314)
    virtual void VirtualFunction198();  // 0x6D0061006E0020 (0x318)
    virtual void VirtualFunction199();  // 0x200065006D0061 (0x31C)
    virtual void VirtualFunction200();  // 0x4E002700200065 (0x320)
    virtual void VirtualFunction201();  // 0x6E006F004E0027 (0x324)
    virtual void VirtualFunction202();  // 0x270065006E006F (0x328)
    virtual void VirtualFunction203();  // 0x20002E00270065 (0x32C)
    virtual void VirtualFunction204();  // 0x6C00430020002E (0x330)
    virtual void VirtualFunction205();  // 0x730061006C0043 (0x334)
    virtual void VirtualFunction206();  // 0x20007300730061 (0x338)
    virtual void VirtualFunction207();  // 0x6C006600200073 (0x33C)
    virtual void VirtualFunction208();  // 0x670061006C0066 (0x340)
    virtual void VirtualFunction209();  // 0x20007300670061 (0x344)
    virtual void VirtualFunction210();  // 0x20003D00200073 (0x348)
    virtual void VirtualFunction211();  // 0x6400250020003D (0x34C)
    virtual void VirtualFunction212();  // 0x00640025 (0x350)
    virtual void VirtualFunction213();  // 0x69002E00000000 (0x354)
    virtual void VirtualFunction214();  // 0x69006E0069002E (0x358)
    virtual void VirtualFunction215();  // 0x0069006E (0x35C)
    virtual void VirtualFunction216();  // 0x00000000 (0x360)
    virtual void VirtualFunction217();  // 0x65004400000000 (0x364)
    virtual void VirtualFunction218();  // 0x61006600650044 (0x368)
    virtual void VirtualFunction219();  // 0x6C007500610066 (0x36C)
    virtual void VirtualFunction220();  // 0x74006C0075 (0x370)
    virtual void VirtualFunction221();  // 0x00000074 (0x374)
    virtual void VirtualFunction222();  // 0x00000000 (0x378)
    virtual void VirtualFunction223();  // 0x9117BE000000000 (0x37C)
    virtual void VirtualFunction224();  // 0x7FF709117BE0 (0x380)
    virtual void VirtualFunction225();  // 0x91860C000007FF7 (0x384)
    virtual void VirtualFunction226();  // 0x7FF7091860C0 (0x388)
    virtual void VirtualFunction227();  // 0x917C09000007FF7 (0x38C)
    virtual void VirtualFunction228();  // 0x7FF70917C090 (0x390)
    virtual void VirtualFunction229();  // 0x9117BE000007FF7 (0x394)
    virtual void VirtualFunction230();  // 0x7FF709117BE0 (0x398)
    virtual void VirtualFunction231();  // 0x913712000007FF7 (0x39C)
    virtual void VirtualFunction232();  // 0x7FF709137120 (0x3A0)
    virtual void VirtualFunction233();  // 0x913712000007FF7 (0x3A4)
    virtual void VirtualFunction234();  // 0x7FF709137120 (0x3A8)
    virtual void VirtualFunction235();  // 0x91DF65000007FF7 (0x3AC)
    virtual void VirtualFunction236();  // 0x7FF7091DF650 (0x3B0)
    virtual void VirtualFunction237();  // 0x91E57B000007FF7 (0x3B4)
    virtual void VirtualFunction238();  // 0x7FF7091E57B0 (0x3B8)
    virtual void VirtualFunction239();  // 0x918AC8000007FF7 (0x3BC)
    virtual void VirtualFunction240();  // 0x7FF70918AC80 (0x3C0)
    virtual void VirtualFunction241();  // 0x91D472000007FF7 (0x3C4)
    virtual void VirtualFunction242();  // 0x7FF7091D4720 (0x3C8)
    virtual void VirtualFunction243();  // 0x9117BE000007FF7 (0x3CC)
    virtual void VirtualFunction244();  // 0x7FF709117BE0 (0x3D0)
    virtual void VirtualFunction245();  // 0x91E734000007FF7 (0x3D4)
    virtual void VirtualFunction246();  // 0x7FF7091E7340 (0x3D8)
    virtual void VirtualFunction247();  // 0x91D8AC000007FF7 (0x3DC)
    virtual void VirtualFunction248();  // 0x7FF7091D8AC0 (0x3E0)
    virtual void VirtualFunction249();  // 0x918E5E000007FF7 (0x3E4)
    virtual void VirtualFunction250();  // 0x7FF70918E5E0 (0x3E8)
    virtual void VirtualFunction251();  // 0x91573E000007FF7 (0x3EC)
    virtual void VirtualFunction252();  // 0x7FF7091573E0 (0x3F0)
    virtual void VirtualFunction253();  // 0x913712000007FF7 (0x3F4)
    virtual void VirtualFunction254();  // 0x7FF709137120 (0x3F8)
    virtual void VirtualFunction255();  // 0x91E0AD000007FF7 (0x3FC)
};

UClass* UObject::pClassPointer = NULL;

// Class Core.TextBuffer
// 0x002C (0x008C - 0x0060)
class UTextBuffer : public UObject {
   public:
    unsigned char UnknownData00[0x2C];  // 0x0060 (0x002C) MISSED OFFSET

   private:
    static UClass* pClassPointer;

   public:
    static UClass* StaticClass() {
        if (!pClassPointer)
            pClassPointer = (UClass*)UObject::GObjObjects()->Data[1];

        return pClassPointer;
    };
};

UClass* UTextBuffer::pClassPointer = NULL;

// Class Core.Subsystem
// 0x0008 (0x0068 - 0x0060)
class USubsystem : public UObject {
   public:
    struct FPointer VfTable_FExec;  // 0x0060 (0x0008) [0x0000000000000000]

   private:
    static UClass* pClassPointer;

   public:
    static UClass* StaticClass() {
        if (!pClassPointer)
            pClassPointer = (UClass*)UObject::GObjObjects()->Data[6];

        return pClassPointer;
    };
};

UClass* USubsystem::pClassPointer = NULL;

// Class Core.System
// 0x00F4 (0x015C - 0x0068)
class USystem : public USubsystem {
   public:
    int StaleCacheDays;            // 0x0068 (0x0004) [0x0000000000000000]
    int MaxStaleCacheSize;         // 0x006C (0x0004) [0x0000000000000000]
    int MaxOverallCacheSize;       // 0x0070 (0x0004) [0x0000000000000000]
    int PackageSizeSoftLimit;      // 0x0074 (0x0004) [0x0000000000000000]
    float AsyncIOBandwidthLimit;   // 0x0078 (0x0004) [0x0000000000000000]
    struct FString SavePath;       // 0x007C (0x0010) [0x0000000000000000]
    struct FString CachePath;      // 0x008C (0x0010) [0x0000000000000000]
    struct FString CacheExt;       // 0x009C (0x0010) [0x0000000000000000]
    TArray<struct FString> Paths;  // 0x00AC (0x0010) [0x0000000000000000]
    TArray<struct FString>
        SeekFreePCPaths;                 // 0x00BC (0x0010) [0x0000000000000000]
    TArray<struct FString> ScriptPaths;  // 0x00CC (0x0010) [0x0000000000000000]
    TArray<struct FString>
        FRScriptPaths;  // 0x00DC (0x0010) [0x0000000000000000]
    TArray<struct FString>
        CutdownPaths;                   // 0x00EC (0x0010) [0x0000000000000000]
    TArray<struct FName> Suppress;      // 0x00FC (0x0010) [0x0000000000000000]
    TArray<struct FString> Extensions;  // 0x010C (0x0010) [0x0000000000000000]
    TArray<struct FString>
        SeekFreePCExtensions;  // 0x011C (0x0010) [0x0000000000000000]
    TArray<struct FString>
        LocalizationPaths;  // 0x012C (0x0010) [0x0000000000000000]
    struct FString
        TextureFileCacheExtension;  // 0x013C (0x0010) [0x0000000000000000]
    TArray<struct FString>
        BrewedPCPaths;  // 0x014C (0x0010) [0x0000000000000000]

   private:
    static UClass* pClassPointer;

   public:
    static UClass* StaticClass() {
        if (!pClassPointer)
            pClassPointer = (UClass*)UObject::GObjObjects()->Data[5];

        return pClassPointer;
    };
};

UClass* USystem::pClassPointer = NULL;

// Class Core.PackageMap
// 0x00A0 (0x0100 - 0x0060)
class UPackageMap : public UObject {
   public:
    unsigned char UnknownData00[0xA0];  // 0x0060 (0x00A0) MISSED OFFSET

   private:
    static UClass* pClassPointer;

   public:
    static UClass* StaticClass() {
        if (!pClassPointer)
            pClassPointer = (UClass*)UObject::GObjObjects()->Data[38];

        return pClassPointer;
    };
};

UClass* UPackageMap::pClassPointer = NULL;

// Class Core.ObjectSerializer
// 0x0010 (0x0070 - 0x0060)
class UObjectSerializer : public UObject {
   public:
    unsigned char UnknownData00[0x10];  // 0x0060 (0x0010) MISSED OFFSET

   private:
    static UClass* pClassPointer;

   public:
    static UClass* StaticClass() {
        if (!pClassPointer)
            pClassPointer = (UClass*)UObject::GObjObjects()->Data[40];

        return pClassPointer;
    };
};

UClass* UObjectSerializer::pClassPointer = NULL;

// Class Core.ObjectRedirector
// 0x0008 (0x0068 - 0x0060)
class UObjectRedirector : public UObject {
   public:
    unsigned char UnknownData00[0x8];  // 0x0060 (0x0008) MISSED OFFSET

   private:
    static UClass* pClassPointer;

   public:
    static UClass* StaticClass() {
        if (!pClassPointer)
            pClassPointer = (UClass*)UObject::GObjObjects()->Data[42];

        return pClassPointer;
    };
};

UClass* UObjectRedirector::pClassPointer = NULL;

// Class Core.MetaData
// 0x0048 (0x00A8 - 0x0060)
class UMetaData : public UObject {
   public:
    unsigned char UnknownData00[0x48];  // 0x0060 (0x0048) MISSED OFFSET

   private:
    static UClass* pClassPointer;

   public:
    static UClass* StaticClass() {
        if (!pClassPointer)
            pClassPointer = (UClass*)UObject::GObjObjects()->Data[44];

        return pClassPointer;
    };
};

UClass* UMetaData::pClassPointer = NULL;

// Class Core.Linker
// 0x0168 (0x01C8 - 0x0060)
class ULinker : public UObject {
   public:
    unsigned char UnknownData00[0x168];  // 0x0060 (0x0168) MISSED OFFSET

   private:
    static UClass* pClassPointer;

   public:
    static UClass* StaticClass() {
        if (!pClassPointer)
            pClassPointer = (UClass*)UObject::GObjObjects()->Data[47];

        return pClassPointer;
    };
};

UClass* ULinker::pClassPointer = NULL;

// Class Core.LinkerSave
// 0x00B4 (0x027C - 0x01C8)
class ULinkerSave : public ULinker {
   public:
    unsigned char UnknownData00[0xB4];  // 0x01C8 (0x00B4) MISSED OFFSET

   private:
    static UClass* pClassPointer;

   public:
    static UClass* StaticClass() {
        if (!pClassPointer)
            pClassPointer = (UClass*)UObject::GObjObjects()->Data[46];

        return pClassPointer;
    };
};

UClass* ULinkerSave::pClassPointer = NULL;

// Class Core.LinkerLoad
// 0x0604 (0x07CC - 0x01C8)
class ULinkerLoad : public ULinker {
   public:
    unsigned char UnknownData00[0x604];  // 0x01C8 (0x0604) MISSED OFFSET

   private:
    static UClass* pClassPointer;

   public:
    static UClass* StaticClass() {
        if (!pClassPointer)
            pClassPointer = (UClass*)UObject::GObjObjects()->Data[50];

        return pClassPointer;
    };
};

UClass* ULinkerLoad::pClassPointer = NULL;

// Class Core.Interface
// 0x0000 (0x0060 - 0x0060)
class UInterface : public UObject {
   public:
   private:
    static UClass* pClassPointer;

   public:
    static UClass* StaticClass() {
        if (!pClassPointer)
            pClassPointer = (UClass*)UObject::GObjObjects()->Data[52];

        return pClassPointer;
    };
};

UClass* UInterface::pClassPointer = NULL;

// Class Core.Field
// 0x0008 (0x0068 - 0x0060)
class UField : public UObject {
   public:
    class UField* Next;

   private:
    static UClass* pClassPointer;

   public:
    static UClass* StaticClass() {
        if (!pClassPointer)
            pClassPointer = (UClass*)UObject::GObjObjects()->Data[56];

        return pClassPointer;
    };
};

UClass* UField::pClassPointer = NULL;

// Class Core.Struct
// 0x0068 (0x00D0 - 0x0068)
class UStruct : public UField {
   public:
    unsigned char UnknownData00[0x10];  // 0x0068 (0x10)
    class UField* SuperField;           // 0x0078 (0x8)
    class UField* Children;             // 0x0080 (0x8)
    int PropertySize;                   // 0x0088 (0x4)
    unsigned char UnknownData01[0x44];  // 0x008C (0x44)

   private:
    static UClass* pClassPointer;

   public:
    static UClass* StaticClass() {
        if (!pClassPointer)
            pClassPointer = (UClass*)UObject::GObjObjects()->Data[55];

        return pClassPointer;
    };
};

UClass* UStruct::pClassPointer = NULL;

// Class Core.ScriptStruct
// 0x0024 (0x00F4 - 0x00D0)
class UScriptStruct : public UStruct {
   public:
    unsigned char UnknownData00[0x24];  // 0x00D0 (0x0024) MISSED OFFSET

   private:
    static UClass* pClassPointer;

   public:
    static UClass* StaticClass() {
        if (!pClassPointer)
            pClassPointer = (UClass*)UObject::GObjObjects()->Data[54];

        return pClassPointer;
    };
};

UClass* UScriptStruct::pClassPointer = NULL;

// Class Core.Function
// 0x0028 (0x00F8 - 0x00D0)
class UFunction : public UStruct {
   public:
    unsigned long FunctionFlags;       // 0x00D0 (0x04)
    unsigned short iNative;            // 0x00D4 (0x02)
    unsigned short RepOffset;          // 0x00D6 (0x02)
    struct FName FriendlyName;         // 0x00D8 (0x08)
    unsigned short NumParms;           // 0x00E0 (0x02)
    unsigned short ParmsSize;          // 0x00E2 (0x02)
    unsigned short ReturnValueOffset;  // 0x00E4 (0x02)
    char UnknownData[0xA];             // 0x00E6 (0x0A)
    void* Func;                        // 0x00F0 (0x08)

   private:
    static UClass* pClassPointer;

   public:
    static UClass* StaticClass() {
        if (!pClassPointer)
            pClassPointer = (UClass*)UObject::GObjObjects()->Data[60];

        return pClassPointer;
    };
};

UClass* UFunction::pClassPointer = NULL;

// Class Core.Property
// 0x0040 (0x00A8 - 0x0068)
class UProperty : public UField {
   public:
    unsigned char UnknownData00[0x40];  // 0x0068 (0x0040) MISSED OFFSET

   private:
    static UClass* pClassPointer;

   public:
    static UClass* StaticClass() {
        if (!pClassPointer)
            pClassPointer = (UClass*)UObject::GObjObjects()->Data[63];

        return pClassPointer;
    };
};

UClass* UProperty::pClassPointer = NULL;

// Class Core.StructProperty
// 0x0008 (0x00B0 - 0x00A8)
class UStructProperty : public UProperty {
   public:
    unsigned char UnknownData00[0x8];  // 0x00A8 (0x0008) MISSED OFFSET

   private:
    static UClass* pClassPointer;

   public:
    static UClass* StaticClass() {
        if (!pClassPointer)
            pClassPointer = (UClass*)UObject::GObjObjects()->Data[62];

        return pClassPointer;
    };
};

UClass* UStructProperty::pClassPointer = NULL;

// Class Core.StrProperty
// 0x0000 (0x00A8 - 0x00A8)
class UStrProperty : public UProperty {
   public:
   private:
    static UClass* pClassPointer;

   public:
    static UClass* StaticClass() {
        if (!pClassPointer)
            pClassPointer = (UClass*)UObject::GObjObjects()->Data[66];

        return pClassPointer;
    };
};

UClass* UStrProperty::pClassPointer = NULL;

// Class Core.ObjectProperty
// 0x0008 (0x00B0 - 0x00A8)
class UObjectProperty : public UProperty {
   public:
    unsigned char UnknownData00[0x8];  // 0x00A8 (0x0008) MISSED OFFSET

   private:
    static UClass* pClassPointer;

   public:
    static UClass* StaticClass() {
        if (!pClassPointer)
            pClassPointer = (UClass*)UObject::GObjObjects()->Data[69];

        return pClassPointer;
    };
};

UClass* UObjectProperty::pClassPointer = NULL;

// Class Core.ComponentProperty
// 0x0000 (0x00B0 - 0x00B0)
class UComponentProperty : public UObjectProperty {
   public:
   private:
    static UClass* pClassPointer;

   public:
    static UClass* StaticClass() {
        if (!pClassPointer)
            pClassPointer = (UClass*)UObject::GObjObjects()->Data[68];

        return pClassPointer;
    };
};

UClass* UComponentProperty::pClassPointer = NULL;

// Class Core.ClassProperty
// 0x0008 (0x00B8 - 0x00B0)
class UClassProperty : public UObjectProperty {
   public:
    unsigned char UnknownData00[0x8];  // 0x00B0 (0x0008) MISSED OFFSET

   private:
    static UClass* pClassPointer;

   public:
    static UClass* StaticClass() {
        if (!pClassPointer)
            pClassPointer = (UClass*)UObject::GObjObjects()->Data[72];

        return pClassPointer;
    };
};

UClass* UClassProperty::pClassPointer = NULL;

// Class Core.NameProperty
// 0x0000 (0x00A8 - 0x00A8)
class UNameProperty : public UProperty {
   public:
   private:
    static UClass* pClassPointer;

   public:
    static UClass* StaticClass() {
        if (!pClassPointer)
            pClassPointer = (UClass*)UObject::GObjObjects()->Data[74];

        return pClassPointer;
    };
};

UClass* UNameProperty::pClassPointer = NULL;

// Class Core.MapProperty
// 0x0010 (0x00B8 - 0x00A8)
class UMapProperty : public UProperty {
   public:
    unsigned char UnknownData00[0x10];  // 0x00A8 (0x0010) MISSED OFFSET

   private:
    static UClass* pClassPointer;

   public:
    static UClass* StaticClass() {
        if (!pClassPointer)
            pClassPointer = (UClass*)UObject::GObjObjects()->Data[76];

        return pClassPointer;
    };
};

UClass* UMapProperty::pClassPointer = NULL;

// Class Core.IntProperty
// 0x0000 (0x00A8 - 0x00A8)
class UIntProperty : public UProperty {
   public:
   private:
    static UClass* pClassPointer;

   public:
    static UClass* StaticClass() {
        if (!pClassPointer)
            pClassPointer = (UClass*)UObject::GObjObjects()->Data[78];

        return pClassPointer;
    };
};

UClass* UIntProperty::pClassPointer = NULL;

// Class Core.InterfaceProperty
// 0x0008 (0x00B0 - 0x00A8)
class UInterfaceProperty : public UProperty {
   public:
    unsigned char UnknownData00[0x8];  // 0x00A8 (0x0008) MISSED OFFSET

   private:
    static UClass* pClassPointer;

   public:
    static UClass* StaticClass() {
        if (!pClassPointer)
            pClassPointer = (UClass*)UObject::GObjObjects()->Data[80];

        return pClassPointer;
    };
};

UClass* UInterfaceProperty::pClassPointer = NULL;

// Class Core.FloatProperty
// 0x0000 (0x00A8 - 0x00A8)
class UFloatProperty : public UProperty {
   public:
   private:
    static UClass* pClassPointer;

   public:
    static UClass* StaticClass() {
        if (!pClassPointer)
            pClassPointer = (UClass*)UObject::GObjObjects()->Data[82];

        return pClassPointer;
    };
};

UClass* UFloatProperty::pClassPointer = NULL;

// Class Core.DelegateProperty
// 0x0010 (0x00B8 - 0x00A8)
class UDelegateProperty : public UProperty {
   public:
    unsigned char UnknownData00[0x10];  // 0x00A8 (0x0010) MISSED OFFSET

   private:
    static UClass* pClassPointer;

   public:
    static UClass* StaticClass() {
        if (!pClassPointer)
            pClassPointer = (UClass*)UObject::GObjObjects()->Data[84];

        return pClassPointer;
    };
};

UClass* UDelegateProperty::pClassPointer = NULL;

// Class Core.ByteProperty
// 0x0008 (0x00B0 - 0x00A8)
class UByteProperty : public UProperty {
   public:
    unsigned char UnknownData00[0x8];  // 0x00A8 (0x0008) MISSED OFFSET

   private:
    static UClass* pClassPointer;

   public:
    static UClass* StaticClass() {
        if (!pClassPointer)
            pClassPointer = (UClass*)UObject::GObjObjects()->Data[86];

        return pClassPointer;
    };
};

UClass* UByteProperty::pClassPointer = NULL;

// Class Core.BoolProperty
// 0x0004 (0x00AC - 0x00A8)
class UBoolProperty : public UProperty {
   public:
    unsigned char UnknownData00[0x4];  // 0x00A8 (0x0004) MISSED OFFSET

   private:
    static UClass* pClassPointer;

   public:
    static UClass* StaticClass() {
        if (!pClassPointer)
            pClassPointer = (UClass*)UObject::GObjObjects()->Data[88];

        return pClassPointer;
    };
};

UClass* UBoolProperty::pClassPointer = NULL;

// Class Core.ArrayProperty
// 0x0008 (0x00B0 - 0x00A8)
class UArrayProperty : public UProperty {
   public:
    unsigned char UnknownData00[0x8];  // 0x00A8 (0x0008) MISSED OFFSET

   private:
    static UClass* pClassPointer;

   public:
    static UClass* StaticClass() {
        if (!pClassPointer)
            pClassPointer = (UClass*)UObject::GObjObjects()->Data[90];

        return pClassPointer;
    };
};

UClass* UArrayProperty::pClassPointer = NULL;

// Class Core.Enum
// 0x0010 (0x0078 - 0x0068)
class UEnum : public UField {
   public:
    unsigned char UnknownData00[0x10];  // 0x0068 (0x0010) MISSED OFFSET

   private:
    static UClass* pClassPointer;

   public:
    static UClass* StaticClass() {
        if (!pClassPointer)
            pClassPointer = (UClass*)UObject::GObjObjects()->Data[92];

        return pClassPointer;
    };
};

UClass* UEnum::pClassPointer = NULL;

// Class Core.Const
// 0x0010 (0x0078 - 0x0068)
class UConst : public UField {
   public:
    unsigned char UnknownData00[0x10];  // 0x0068 (0x0010) MISSED OFFSET

   private:
    static UClass* pClassPointer;

   public:
    static UClass* StaticClass() {
        if (!pClassPointer)
            pClassPointer = (UClass*)UObject::GObjObjects()->Data[94];

        return pClassPointer;
    };
};

UClass* UConst::pClassPointer = NULL;

// Class Core.Factory
// 0x0048 (0x00A8 - 0x0060)
class UFactory : public UObject {
   public:
    class UClass* SupportedClass;    // 0x0060 (0x0008) [0x0000000000000000]
    class UClass* ContextClass;      // 0x0068 (0x0008) [0x0000000000000000]
    struct FString Description;      // 0x0070 (0x0010) [0x0000000000000000]
    TArray<struct FString> Formats;  // 0x0080 (0x0010) [0x0000000000000000]
    DWORD bCreateNew : 1;  // 0x0090 (0x0004) [0x0000000000000000] [0x00000001]
    DWORD
        bEditAfterNew : 1;  // 0x0090 (0x0004) [0x0000000000000000] [0x00000002]
    DWORD
        bEditorImport : 1;  // 0x0090 (0x0004) [0x0000000000000000] [0x00000004]
    DWORD bText : 1;        // 0x0090 (0x0004) [0x0000000000000000] [0x00000008]
    int AutoPriority;       // 0x0094 (0x0004) [0x0000000000000000]
    TArray<struct FString>
        ValidGameNames;  // 0x0098 (0x0010) [0x0000000000000000]

   private:
    static UClass* pClassPointer;

   public:
    static UClass* StaticClass() {
        if (!pClassPointer)
            pClassPointer = (UClass*)UObject::GObjObjects()->Data[97];

        return pClassPointer;
    };
};

UClass* UFactory::pClassPointer = NULL;

// Class Core.TextBufferFactory
// 0x0000 (0x00A8 - 0x00A8)
class UTextBufferFactory : public UFactory {
   public:
   private:
    static UClass* pClassPointer;

   public:
    static UClass* StaticClass() {
        if (!pClassPointer)
            pClassPointer = (UClass*)UObject::GObjObjects()->Data[96];

        return pClassPointer;
    };
};

UClass* UTextBufferFactory::pClassPointer = NULL;

// Class Core.Exporter
// 0x0034 (0x0094 - 0x0060)
class UExporter : public UObject {
   public:
    unsigned char UnknownData00[0x8];  // 0x0060 (0x0008) MISSED OFFSET
    TArray<struct FString>
        FormatExtension;  // 0x0068 (0x0010) [0x0000000000000000]
    TArray<struct FString>
        FormatDescription;             // 0x0078 (0x0010) [0x0000000000000000]
    unsigned char UnknownData01[0xC];  // 0x0088 (0x000C) MISSED OFFSET

   private:
    static UClass* pClassPointer;

   public:
    static UClass* StaticClass() {
        if (!pClassPointer)
            pClassPointer = (UClass*)UObject::GObjObjects()->Data[100];

        return pClassPointer;
    };
};

UClass* UExporter::pClassPointer = NULL;

// Class Core.Component
// 0x0010 (0x0070 - 0x0060)
class UComponent : public UObject {
   public:
    class UClass* TemplateOwnerClass;  // 0x0060 (0x0008) [0x0000000000000000]
    struct FName TemplateName;         // 0x0068 (0x0008) [0x0000000000000000]

   private:
    static UClass* pClassPointer;

   public:
    static UClass* StaticClass() {
        if (!pClassPointer)
            pClassPointer = (UClass*)UObject::GObjObjects()->Data[107];

        return pClassPointer;
    };
};

UClass* UComponent::pClassPointer = NULL;

// Class Core.DistributionVector
// 0x000C (0x007C - 0x0070)
class UDistributionVector : public UComponent {
   public:
    struct FPointer
        VfTable_FCurveEdInterface;  // 0x0070 (0x0008) [0x0000000000000000]
    DWORD bCanBeBaked : 1;  // 0x0078 (0x0004) [0x0000000000000000] [0x00000001]
    DWORD bIsDirty : 1;     // 0x0078 (0x0004) [0x0000000000000000] [0x00000002]

   private:
    static UClass* pClassPointer;

   public:
    static UClass* StaticClass() {
        if (!pClassPointer)
            pClassPointer = (UClass*)UObject::GObjObjects()->Data[106];

        return pClassPointer;
    };

    void GetVectorValue();
};

UClass* UDistributionVector::pClassPointer = NULL;

// Class Core.DistributionFloat
// 0x000C (0x007C - 0x0070)
class UDistributionFloat : public UComponent {
   public:
    struct FPointer
        VfTable_FCurveEdInterface;  // 0x0070 (0x0008) [0x0000000000000000]
    DWORD bCanBeBaked : 1;  // 0x0078 (0x0004) [0x0000000000000000] [0x00000001]
    DWORD bIsDirty : 1;     // 0x0078 (0x0004) [0x0000000000000000] [0x00000002]

   private:
    static UClass* pClassPointer;

   public:
    static UClass* StaticClass() {
        if (!pClassPointer)
            pClassPointer = (UClass*)UObject::GObjObjects()->Data[110];

        return pClassPointer;
    };

    void GetFloatValue();
};

UClass* UDistributionFloat::pClassPointer = NULL;

// Class Core.Commandlet
// 0x0054 (0x00B4 - 0x0060)
class UCommandlet : public UObject {
   public:
    struct FString HelpDescription;  // 0x0060 (0x0010) [0x0000000000000000]
    struct FString HelpUsage;        // 0x0070 (0x0010) [0x0000000000000000]
    struct FString HelpWebLink;      // 0x0080 (0x0010) [0x0000000000000000]
    TArray<struct FString>
        HelpParamNames;  // 0x0090 (0x0010) [0x0000000000000000]
    TArray<struct FString>
        HelpParamDescriptions;  // 0x00A0 (0x0010) [0x0000000000000000]
    DWORD IsServer : 1;  // 0x00B0 (0x0004) [0x0000000000000000] [0x00000001]
    DWORD IsClient : 1;  // 0x00B0 (0x0004) [0x0000000000000000] [0x00000002]
    DWORD IsEditor : 1;  // 0x00B0 (0x0004) [0x0000000000000000] [0x00000004]
    DWORD
        LogToConsole : 1;  // 0x00B0 (0x0004) [0x0000000000000000] [0x00000008]
    DWORD ShowErrorCount : 1;  // 0x00B0 (0x0004) [0x0000000000000000]
                               // [0x00000010]

   private:
    static UClass* pClassPointer;

   public:
    static UClass* StaticClass() {
        if (!pClassPointer)
            pClassPointer = (UClass*)UObject::GObjObjects()->Data[113];

        return pClassPointer;
    };

    void eventMain();
};

UClass* UCommandlet::pClassPointer = NULL;

// Class Core.HelpCommandlet
// 0x0000 (0x00B4 - 0x00B4)
class UHelpCommandlet : public UCommandlet {
   public:
   private:
    static UClass* pClassPointer;

   public:
    static UClass* StaticClass() {
        if (!pClassPointer)
            pClassPointer = (UClass*)UObject::GObjObjects()->Data[112];

        return pClassPointer;
    };

    void eventMain();
};

UClass* UHelpCommandlet::pClassPointer = NULL;

// Class Core.State
// 0x0054 (0x0124 - 0x00D0)
class UState : public UStruct {
   public:
    unsigned char UnknownData00[0x54];  // 0x00D0 (0x0054) MISSED OFFSET

   private:
    static UClass* pClassPointer;

   public:
    static UClass* StaticClass() {
        if (!pClassPointer)
            pClassPointer = (UClass*)UObject::GObjObjects()->Data[116];

        return pClassPointer;
    };
};

UClass* UState::pClassPointer = NULL;

// Class Core.Package
// 0x00D4 (0x0134 - 0x0060)
class UPackage : public UObject {
   public:
    unsigned char UnknownData00[0xD4];  // 0x0060 (0x00D4) MISSED OFFSET

   private:
    static UClass* pClassPointer;

   public:
    static UClass* StaticClass() {
        if (!pClassPointer)
            pClassPointer = (UClass*)UObject::GObjObjects()->Data[118];

        return pClassPointer;
    };
};

UClass* UPackage::pClassPointer = NULL;

// Class Core.Class
// 0x014C (0x0270 - 0x0124)
class UClass : public UState {
   public:
    unsigned char UnknownData00[0x14C];  // 0x0124 (0x014C) MISSED OFFSET

   private:
    static UClass* pClassPointer;

   public:
    static UClass* StaticClass() {
        if (!pClassPointer)
            pClassPointer = (UClass*)UObject::GObjObjects()->Data[120];

        return pClassPointer;
    };
};

UClass* UClass::pClassPointer = NULL;

#ifdef _MSC_VER
#pragma pack(pop)
#endif