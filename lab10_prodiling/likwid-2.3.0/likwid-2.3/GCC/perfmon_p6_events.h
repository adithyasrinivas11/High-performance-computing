/* DONT TOUCH: GENERATED FILE! */

#define NUM_ARCH_EVENTS_P6 117

static PerfmonEvent  p6_arch_events[NUM_ARCH_EVENTS_P6] = {
 {"DATA_MEM_REFS",
   "PMC", 
   0x43,0x00,0,0}
, {"DCU_LINES_IN",
   "PMC", 
   0x45,0x00,0,0}
, {"DCU_M_LINES_IN",
   "PMC", 
   0x46,0x00,0,0}
, {"DCU_M_LINES_OUT",
   "PMC", 
   0x47,0x00,0,0}
, {"DCU_MISS_OUTSTANDING",
   "PMC", 
   0x48,0x00,0,0}
, {"IFU_IFETCH",
   "PMC", 
   0x80,0x00,0,0}
, {"IFU_IFETCH_MISS",
   "PMC", 
   0x81,0x00,0,0}
, {"ITLB_MISS",
   "PMC", 
   0x85,0x00,0,0}
, {"IFU_MEM_STALL",
   "PMC", 
   0x86,0x00,0,0}
, {"ILD_STALL",
   "PMC", 
   0x87,0x00,0,0}
, {"L2_IFETCH",
   "PMC", 
   0x28,0x0F,0,0}
, {"L2_LD",
   "PMC", 
   0x29,0x0F,0,0}
, {"L2_ST",
   "PMC", 
   0x2A,0x0F,0,0}
, {"L2_LINES_IN",
   "PMC", 
   0x24,0x00,0,0}
, {"L2_LINES_OUT",
   "PMC", 
   0x26,0x00,0,0}
, {"L2_LINES_INM",
   "PMC", 
   0x25,0x00,0,0}
, {"L2_LINES_OUTM",
   "PMC", 
   0x27,0x00,0,0}
, {"L2_RQSTS",
   "PMC", 
   0x2E,0x00,0,0}
, {"L2_ADS",
   "PMC", 
   0x21,0x00,0,0}
, {"L2_DBUS_BUSY",
   "PMC", 
   0x22,0x00,0,0}
, {"L2_DBUS_BUSY_RD",
   "PMC", 
   0x23,0x00,0,0}
, {"BUS_DRDY_CLOCKS_SELF",
   "PMC", 
   0x62,0x00,0,0}
, {"BUS_DRDY_CLOCKS_ANY",
   "PMC", 
   0x62,0x20,0,0}
, {"BUS_LOCK_CLOCKS_SELF",
   "PMC", 
   0x63,0x00,0,0}
, {"BUS_LOCK_CLOCKS_ANY",
   "PMC", 
   0x63,0x20,0,0}
, {"BUS_REQ_OUTSTANDING_SELF",
   "PMC", 
   0x60,0x00,0,0}
, {"BUS_TRAN_BRD_SELF",
   "PMC", 
   0x65,0x00,0,0}
, {"BUS_TRAN_BRD_ANY",
   "PMC", 
   0x65,0x20,0,0}
, {"BUS_TRAN_RFO_SELF",
   "PMC", 
   0x66,0x00,0,0}
, {"BUS_TRAN_RFO_ANY",
   "PMC", 
   0x66,0x20,0,0}
, {"BUS_TRAN_WB_SELF",
   "PMC", 
   0x67,0x00,0,0}
, {"BUS_TRAN_WB_ANY",
   "PMC", 
   0x67,0x20,0,0}
, {"BUS_TRAN_IFETCH_SELF",
   "PMC", 
   0x68,0x00,0,0}
, {"BUS_TRAN_IFETCH_ANY",
   "PMC", 
   0x68,0x20,0,0}
, {"BUS_TRAN_INVAL_SELF",
   "PMC", 
   0x69,0x00,0,0}
, {"BUS_TRAN_INVAL_ANY",
   "PMC", 
   0x69,0x20,0,0}
, {"BUS_TRAN_PWR_SELF",
   "PMC", 
   0x6A,0x00,0,0}
, {"BUS_TRAN_PWR_ANY",
   "PMC", 
   0x6A,0x20,0,0}
, {"BUS_TRANS_P_SELF",
   "PMC", 
   0x6B,0x00,0,0}
, {"BUS_TRANS_P_ANY",
   "PMC", 
   0x6B,0x20,0,0}
, {"BUS_TRANS_IO_SELF",
   "PMC", 
   0x6C,0x00,0,0}
, {"BUS_TRANS_IO_ANY",
   "PMC", 
   0x6C,0x20,0,0}
, {"BUS_TRAN_DEF_SELF",
   "PMC", 
   0x6D,0x00,0,0}
, {"BUS_TRAN_DEF_ANY",
   "PMC", 
   0x6D,0x20,0,0}
, {"BUS_TRAN_BURST_SELF",
   "PMC", 
   0x6E,0x00,0,0}
, {"BUS_TRAN_BURST_ANY",
   "PMC", 
   0x6E,0x20,0,0}
, {"BUS_TRAN_ANY_SELF",
   "PMC", 
   0x70,0x00,0,0}
, {"BUS_TRAN_ANY_ANY",
   "PMC", 
   0x70,0x20,0,0}
, {"BUS_TRAN_MEM_SELF",
   "PMC", 
   0x6F,0x00,0,0}
, {"BUS_TRAN_MEM_ANY",
   "PMC", 
   0x6F,0x20,0,0}
, {"BUS_DATA_RCV_SELF",
   "PMC", 
   0x64,0x00,0,0}
, {"BUS_BNR_DRV_SELF",
   "PMC", 
   0x61,0x00,0,0}
, {"BUS_HIT_DRV_SELF",
   "PMC", 
   0x7A,0x00,0,0}
, {"BUS_HITM_DRV_SELF",
   "PMC", 
   0x7B,0x00,0,0}
, {"BUS_SNOOP_STALL_SELF",
   "PMC", 
   0x7E,0x00,0,0}
, {"FLOPS",
   "PMC", 
   0xC1,0x00,0,0}
, {"FP_COMP_OPS_EXE",
   "PMC", 
   0x10,0x00,0,0}
, {"FP_ASSIST",
   "PMC", 
   0x11,0x00,0,0}
, {"MUL",
   "PMC", 
   0x12,0x00,0,0}
, {"DIV",
   "PMC", 
   0x13,0x00,0,0}
, {"CYCLES_DIV_BUSY",
   "PMC", 
   0x14,0x00,0,0}
, {"LD_BLOCKS",
   "PMC", 
   0x03,0x00,0,0}
, {"SB_DRAINS",
   "PMC", 
   0x04,0x00,0,0}
, {"MISALIGN_MEM_REF",
   "PMC", 
   0x05,0x00,0,0}
, {"EMON_KNI_PREF_DISPATCHED_NTA",
   "PMC", 
   0x07,0x00,0,0}
, {"EMON_KNI_PREF_DISPATCHED_T1",
   "PMC", 
   0x07,0x01,0,0}
, {"EMON_KNI_PREF_DISPATCHED_T2",
   "PMC", 
   0x07,0x02,0,0}
, {"EMON_KNI_PREF_DISPATCHED_WEAK",
   "PMC", 
   0x07,0x03,0,0}
, {"EMON_KNI_PREF_MISS_NTA",
   "PMC", 
   0x4B,0x00,0,0}
, {"EMON_KNI_PREF_MISS_T1",
   "PMC", 
   0x4B,0x01,0,0}
, {"EMON_KNI_PREF_MISS_T2",
   "PMC", 
   0x4B,0x02,0,0}
, {"EMON_KNI_PREF_MISS_WEAK",
   "PMC", 
   0x4B,0x03,0,0}
, {"INST_RETIRED",
   "PMC", 
   0xC0,0x00,0,0}
, {"UOPS_RETIRED",
   "PMC", 
   0xC2,0x00,0,0}
, {"INST_DECODED",
   "PMC", 
   0xD0,0x00,0,0}
, {"EMON_KNI_INST_RETIRED_ALL",
   "PMC", 
   0xD8,0x00,0,0}
, {"EMON_KNI_INST_RETIRED_SCALAR",
   "PMC", 
   0xD8,0x01,0,0}
, {"EMON_KNI_COMP_INST_RETIRED_ALL",
   "PMC", 
   0xD9,0x00,0,0}
, {"EMON_KNI_COMP_INST_RETIRED_SCALAR",
   "PMC", 
   0xD9,0x01,0,0}
, {"HW_INT_RX",
   "PMC", 
   0xC8,0x00,0,0}
, {"CYCLES_INT_MASKED",
   "PMC", 
   0xC6,0x00,0,0}
, {"CYCLES_INT_PENDING_AND_MASKED",
   "PMC", 
   0xC7,0x00,0,0}
, {"BR_INST_RETIRED",
   "PMC", 
   0xC4,0x00,0,0}
, {"BR_MISS_PRED_RETIRED",
   "PMC", 
   0xC5,0x00,0,0}
, {"BR_TAKEN_RETIRED",
   "PMC", 
   0xC9,0x00,0,0}
, {"BR_MISS_PRED_TAKEN_RET",
   "PMC", 
   0xCA,0x00,0,0}
, {"BR_INST_DECODED",
   "PMC", 
   0xE0,0x00,0,0}
, {"BTB_MISSES",
   "PMC", 
   0xE2,0x00,0,0}
, {"BR_BOGUS",
   "PMC", 
   0xE4,0x00,0,0}
, {"BACLEARS",
   "PMC", 
   0xE6,0x00,0,0}
, {"RESOURCE_STALLS",
   "PMC", 
   0xA2,0x00,0,0}
, {"PARTIAL_RAT_STALL",
   "PMC", 
   0xD2,0x00,0,0}
, {"SEGMENT_REG_LOADS",
   "PMC", 
   0x06,0x00,0,0}
, {"CPU_CLK_UNHALTED",
   "PMC", 
   0x79,0x00,0,0}
, {"CPU_CLK_UNHALTED",
   "PMC", 
   0x79,0x00,0,0}
, {"MMX_INSTR_EXEC",
   "PMC", 
   0xB0,0x00,0,0}
, {"MMX_SAT_INSTR_EXEC",
   "PMC", 
   0xB1,0x00,0,0}
, {"MMX_UOPS_EXEC",
   "PMC", 
   0xB2,0x0F,0,0}
, {"MMX_INSTR_TYPE_EXEC_PACKED_MUL",
   "PMC", 
   0xB3,0x01,0,0}
, {"MMX_INSTR_TYPE_EXEC_PACKED_SHIFT",
   "PMC", 
   0xB3,0x02,0,0}
, {"MMX_INSTR_TYPE_EXEC_PACK",
   "PMC", 
   0xB3,0x04,0,0}
, {"MMX_INSTR_TYPE_EXEC_UNPACK",
   "PMC", 
   0xB3,0x08,0,0}
, {"MMX_INSTR_TYPE_EXEC_PACKED_LOGICAL",
   "PMC", 
   0xB3,0x10,0,0}
, {"MMX_INSTR_TYPE_EXEC_PACKED_ARITHMETIC",
   "PMC", 
   0xB3,0x20,0,0}
, {"FP_MMX_TRANS_MMX_FP",
   "PMC", 
   0xCC,0x00,0,0}
, {"FP_MMX_TRANS_FP_MMX",
   "PMC", 
   0xCC,0x01,0,0}
, {"MMX_ASSIST",
   "PMC", 
   0xCD,0x00,0,0}
, {"MMX_INSTR_RET",
   "PMC", 
   0xCE,0x00,0,0}
, {"SEG_RENAME_STALLS_ES",
   "PMC", 
   0xD4,0x02,0,0}
, {"SEG_RENAME_STALLS_DS",
   "PMC", 
   0xD4,0x04,0,0}
, {"SEG_RENAME_STALLS_FS",
   "PMC", 
   0xD4,0x08,0,0}
, {"SEG_RENAME_STALLS_ALL",
   "PMC", 
   0xD4,0x0F,0,0}
, {"SEG_REG_RENAMES",
   "PMC", 
   0xD5,0x02,0,0}
, {"SEG_REG_RENAMES",
   "PMC", 
   0xD5,0x04,0,0}
, {"SEG_REG_RENAMES",
   "PMC", 
   0xD5,0x08,0,0}
, {"SEG_REG_RENAMES",
   "PMC", 
   0xD5,0x0F,0,0}
, {"RET_SEG_RENAMES",
   "PMC", 
   0xD6,0x00,0,0}
};
