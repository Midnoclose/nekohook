
/*
 *
 * Client Class, no idea what to call this.
 * Maybe just easy way to get class names
 *
 */

#pragma once

#include "../public/icliententity.h"

enum PropType {
    DPT_Int,
    DPT_Float,
    DPT_Vector,
    DPT_VectorXY,  // Only encodes the XY of a vector, ignores Z
    DPT_String,
    DPT_Array,  // An array of the base types (can't be of datatables).
    DPT_DataTable,
    DPT_Int64
};
static const char* prop_type_str[] = {"int",        "float",  "vector",
                                      "vectorxy",   "string", "array",
                                      "data-table", "int64"};

class RecvTable;
class RecvProp {
   public:
    const char* name;
    const PropType type = DPT_Int;
    const int flags = 0;
    const int str_size = 0;

   private:
    bool m_bInsideArray;  // Set to true by the engine if this property sits
                          // inside an array.
    const void* m_pExtraData;  // Extra data that certain special property types
                               // bind to the property here.
    RecvProp* m_pArrayProp;    // If this is an array (DPT_Array).
    using ArrayLengthRecvProxyFn = void*;
    ArrayLengthRecvProxyFn m_ArrayLengthProxy;
    // Callbacks
    using RecvVarProxyFn = void*;
    RecvVarProxyFn m_ProxyFn;
    using DataTableRecvVarProxyFn = void*;
    DataTableRecvVarProxyFn m_DataTableProxyFn;  // For RDT_DataTable.
   public:
    RecvTable* table;      // For RDT_DataTable.
    const int offset = 0;  // offset from an entity to the requested property
   private:
    int m_ElementStride;
    int m_nElements;
    // If it's one of the numbered "000", "001", etc properties in an array,
    // then these can be used to get its array property name for debugging.
    const char* m_pParentArrayPropName;
};

class CRecvDecoder;
class RecvTable {
   public:
    // Properties described in a table.
    const RecvProp* props;
    const int size = 0;

    const CRecvDecoder* m_pDecoder;
    const char* name;  // The name matched between client and server.
   private:
    bool m_bInitialized;
    bool m_bInMainList;
};

// The serial number that gets passed in is used for ehandles.
using CreateClientClassFn = IClientNetworkable* (*)(int entnum, int serialNum);
using CreateEventFn = IClientNetworkable* (*)();

class ClientClass {
    CreateClientClassFn m_pCreateFn;
    CreateEventFn m_pCreateEventFn;  // Only called for event objects.
   public:
    const char* name;
    RecvTable* table;
    ClientClass* next;
    int id;  // Managed by the engine.
};
