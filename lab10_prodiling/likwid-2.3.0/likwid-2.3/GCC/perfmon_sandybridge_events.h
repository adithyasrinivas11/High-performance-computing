/* DONT TOUCH: GENERATED FILE! */

#define NUM_ARCH_EVENTS_SANDYBRIDGE 220

static PerfmonEvent  sandybridge_arch_events[NUM_ARCH_EVENTS_SANDYBRIDGE] = {
 {"PWR_PKG_ENERGY",
   "PWR", 
   0x00,0x00,0,0}
, {"PWR_PP0_ENERGY",
   "PWR", 
   0x00,0x00,0,0}
, {"PWR_DRAM_ENERGY",
   "PWR", 
   0x00,0x00,0,0}
, {"INSTR_RETIRED_ANY",
   "FIXC0", 
   0x00,0x00,0,0}
, {"CPU_CLK_UNHALTED_CORE",
   "FIXC1", 
   0x00,0x00,0,0}
, {"CPU_CLK_UNHALTED_REF",
   "FIXC2", 
   0x00,0x00,0,0}
, {"LOAD_BLOCKS_DATA_UNKNOWN",
   "PMC", 
   0x03,0x01,0,0}
, {"LOAD_BLOCKS_STORE_FORWARD",
   "PMC", 
   0x03,0x02,0,0}
, {"LOAD_BLOCKS_NO_SR",
   "PMC", 
   0x03,0x08,0,0}
, {"LOAD_BLOCKS_ALL_BLOCK",
   "PMC", 
   0x03,0x10,0,0}
, {"MISALIGN_MEM_REF_LOAD",
   "PMC", 
   0x05,0x01,0,0}
, {"MISALIGN_MEM_REF_STORE",
   "PMC", 
   0x05,0x02,0,0}
, {"MISALIGN_MEM_REF_ANY",
   "PMC", 
   0x05,0x03,0,0}
, {"LD_BLOCKS_PARTIAL_ADDRESS_ALIAS",
   "PMC", 
   0x07,0x01,0,0}
, {"LD_BLOCKS_PARTIAL_ALL_STA_BLOCK",
   "PMC", 
   0x07,0x08,0,0}
, {"DTLB_LOAD_MISSES_CAUSES_A_WALK",
   "PMC", 
   0x08,0x01,0,0}
, {"DTLB_LOAD_MISSES_WALK_COMPLETED",
   "PMC", 
   0x08,0x02,0,0}
, {"DTLB_LOAD_MISSES_WALK_DURATION",
   "PMC", 
   0x08,0x04,0,0}
, {"INT_MISC_RECOVERY_CYCLES",
   "PMC", 
   0x0D,0x03,0x41,0x01}
, {"INT_MISC_STALL_CYCLES",
   "PMC", 
   0x0D,0x40,0,0}
, {"UOPS_ISSUED_ANY",
   "PMC", 
   0x0E,0x01,0,0}
, {"FP_COMP_OPS_EXE_X87",
   "PMC", 
   0x10,0x01,0,0}
, {"FP_COMP_OPS_EXE_SSE_FP_PACKED_DOUBLE",
   "PMC", 
   0x10,0x10,0,0}
, {"FP_COMP_OPS_EXE_SSE_FP_SCALAR_SINGLE",
   "PMC", 
   0x10,0x20,0,0}
, {"FP_COMP_OPS_EXE_SSE_FP_PACKED_SINGLE",
   "PMC", 
   0x10,0x40,0,0}
, {"FP_COMP_OPS_EXE_SSE_FP_SCALAR_DOUBLE",
   "PMC", 
   0x10,0x80,0,0}
, {"FP_256_PACKED_SINGLE",
   "PMC", 
   0x11,0x01,0,0}
, {"FP_256_PACKED_DOUBLE",
   "PMC", 
   0x11,0x02,0,0}
, {"ARITH_FPU_DIV_ACTIVE",
   "PMC", 
   0x14,0x01,0,0}
, {"ARITH_NUM_DIV",
   "PMC", 
   0x14,0x01,0xC5,0x01}
, {"INSTS_WRITTEN_TO_IQ_INSTS",
   "PMC", 
   0x17,0x01,0,0}
, {"L2_RQSTS_ALL_DEM_AND_DATA_RD_HIT",
   "PMC", 
   0x24,0x01,0,0}
, {"L2_RQSTS_ALL_DEM_AND_DATA_RD",
   "PMC", 
   0x24,0x03,0,0}
, {"L2_RQSTS_RFO_HITS",
   "PMC", 
   0x24,0x04,0,0}
, {"L2_RQSTS_RFO_MISS",
   "PMC", 
   0x24,0x08,0,0}
, {"L2_RQSTS_RFO_ANY",
   "PMC", 
   0x24,0x0C,0,0}
, {"L2_RQSTS_CODE_RD_HITS",
   "PMC", 
   0x24,0x10,0,0}
, {"L2_RQSTS_CODE_RD_MISS",
   "PMC", 
   0x24,0x20,0,0}
, {"L2_RQSTS_ALL_CODE_CODE_RD",
   "PMC", 
   0x24,0x30,0,0}
, {"L2_RQSTS_PF_HIT",
   "PMC", 
   0x24,0x40,0,0}
, {"L2_RQSTS_PF_MISS",
   "PMC", 
   0x24,0x80,0,0}
, {"L2_RQSTS_ALL_PF",
   "PMC", 
   0x24,0xC0,0,0}
, {"L2_RQSTS_MISS",
   "PMC", 
   0x24,0xAA,0,0}
, {"L2_STORE_LOCK_RQSTS_MISS",
   "PMC", 
   0x27,0x01,0,0}
, {"L2_STORE_LOCK_RQSTS_HIT_E",
   "PMC", 
   0x27,0x04,0,0}
, {"L2_STORE_LOCK_RQSTS_HIT_M",
   "PMC", 
   0x27,0x08,0,0}
, {"L2_STORE_LOCK_RQSTS_ALL",
   "PMC", 
   0x27,0x0F,0,0}
, {"L1D_WB_RQST_HIT_E",
   "PMC", 
   0x28,0x04,0,0}
, {"L1D_WB_RQST_HIT_M",
   "PMC", 
   0x28,0x08,0,0}
, {"L3_LAT_CACHE_REFERENCE",
   "PMC", 
   0x2E,0x4F,0,0}
, {"L3_LAT_CACHE_MISS",
   "PMC", 
   0x2E,0x41,0,0}
, {"CPU_CLOCK_UNHALTED_THREAD_P",
   "PMC", 
   0x3C,0x00,0,0}
, {"CPU_CLOCK_UNHALTED_REF_P",
   "PMC", 
   0x3C,0x01,0,0}
, {"L1D_PEND_MISS_PENDING",
   "PMC1", 
   0x48,0x01,0,0}
, {"DTLB_STORE_MISSES_MISS_CAUSES_A_WALK",
   "PMC", 
   0x49,0x01,0,0}
, {"DTLB_STORE_MISSES_WALK_COMPLETED",
   "PMC", 
   0x49,0x02,0,0}
, {"DTLB_STORE_MISSES_WALK_DURATION",
   "PMC", 
   0x49,0x04,0,0}
, {"DTLB_STORE_MISSES_STLB_HIT",
   "PMC", 
   0x49,0x10,0,0}
, {"LOAD_HIT_PRE_SW_PF",
   "PMC", 
   0x4C,0x01,0,0}
, {"LOAD_HIT_PRE_HW_PF",
   "PMC", 
   0x4C,0x02,0,0}
, {"HW_PRE_REQ_DL1_MISS",
   "PMC", 
   0x4E,0x02,0,0}
, {"L1D_REPLACEMENT",
   "PMC", 
   0x51,0x01,0,0}
, {"L1D_ALLOCATED_IN_M",
   "PMC", 
   0x51,0x02,0,0}
, {"L1D_M_EVICT",
   "PMC", 
   0x51,0x04,0,0}
, {"L1D_ALL_M_REPLACEMENT",
   "PMC", 
   0x51,0x08,0,0}
, {"PARTIAL_RAT_STALLS_FLAGS_MERGE_UOP",
   "PMC", 
   0x59,0x20,0,0}
, {"PARTIAL_RAT_STALLS_SLOW_LEA_WINDOW",
   "PMC", 
   0x59,0x40,0,0}
, {"PARTIAL_RAT_STALLS_MUL_SINGLE_UOP",
   "PMC", 
   0x59,0x80,0,0}
, {"RESOURCE_STALLS2_ALL_FL_EMPTY",
   "PMC", 
   0x5B,0x0C,0,0}
, {"RESOURCE_STALLS2_ALL_PRF_CONTROL",
   "PMC", 
   0x5B,0x0F,0,0}
, {"RESOURCE_STALLS2_BOB_FULL",
   "PMC", 
   0x5B,0x40,0,0}
, {"RESOURCE_STALLS2_OOO_RSRC",
   "PMC", 
   0x5B,0x4F,0,0}
, {"CPL_CYCLES_RING0",
   "PMC", 
   0x5C,0x01,0,0}
, {"CPL_CYCLES_RING123",
   "PMC", 
   0x5C,0x02,0,0}
, {"RS_EVENTS_EMPTY_CYCLES",
   "PMC", 
   0x5E,0x01,0,0}
, {"OFFCORE_REQUESTS_OUTSTANDING_DEMAND_DATA_RD",
   "PMC", 
   0x60,0x01,0,0}
, {"OFFCORE_REQUESTS_OUTSTANDING_DEMAND_CODE_RD",
   "PMC", 
   0x60,0x02,0,0}
, {"OFFCORE_REQUESTS_OUTSTANDING_DEMAND_RFO",
   "PMC", 
   0x60,0x04,0,0}
, {"OFFCORE_REQUESTS_OUTSTANDING_ALL_DATA_RD",
   "PMC", 
   0x60,0x08,0,0}
, {"CACHE_LOCK_CYCLES_SPLIT_LOCK_UC_LOCK_DURATION",
   "PMC", 
   0x63,0x01,0,0}
, {"CACHE_LOCK_CYCLES_CACHE_LOCK_DURATION",
   "PMC", 
   0x63,0x02,0,0}
, {"IDQ_EMPTY",
   "PMC", 
   0x79,0x02,0,0}
, {"IDQ_MITE_UOPS",
   "PMC", 
   0x79,0x04,0,0}
, {"IDQ_DSB_UOPS",
   "PMC", 
   0x79,0x08,0,0}
, {"IDQ_MS_DSB_UOPS",
   "PMC", 
   0x79,0x10,0,0}
, {"IDQ_MS_MITE_UOPS",
   "PMC", 
   0x79,0x20,0,0}
, {"IDQ_MS_UOPS",
   "PMC", 
   0x79,0x30,0,0}
, {"ICACHE_MISSES",
   "PMC", 
   0x80,0x02,0,0}
, {"ITLB_MISSES_CAUSES_A_WALK",
   "PMC", 
   0x85,0x01,0,0}
, {"ITLB_MISSES_WALK_COMPLETED",
   "PMC", 
   0x85,0x02,0,0}
, {"ITLB_MISSES_WALK_DURATION",
   "PMC", 
   0x85,0x04,0,0}
, {"ITLB_MISSES_STLB_HIT",
   "PMC", 
   0x85,0x10,0,0}
, {"ILD_STALL_LCP",
   "PMC", 
   0x87,0x01,0,0}
, {"ILD_STALL_IQ_FULL",
   "PMC", 
   0x87,0x04,0,0}
, {"BR_INST_EXEC_COND_TAKEN",
   "PMC", 
   0x88,0x81,0,0}
, {"BR_INST_EXEC_COND_NON_TAKEN",
   "PMC", 
   0x88,0x41,0,0}
, {"BR_INST_EXEC_DIRECT_JMP_TAKEN",
   "PMC", 
   0x88,0x82,0,0}
, {"BR_INST_EXEC_DIRECT_JMP_NON_TAKEN",
   "PMC", 
   0x88,0x42,0,0}
, {"BR_INST_EXEC_INDIRECT_JMP_NON_CALL_RET_TAKEN",
   "PMC", 
   0x88,0x84,0,0}
, {"BR_INST_EXEC_INDIRECT_JMP_NON_CALL_RET_NON_TAKEN",
   "PMC", 
   0x88,0x44,0,0}
, {"BR_INST_EXEC_RETURN_NEAR_TAKEN",
   "PMC", 
   0x88,0x88,0,0}
, {"BR_INST_EXEC_RETURN_NEAR_NON_TAKEN",
   "PMC", 
   0x88,0x48,0,0}
, {"BR_INST_EXEC_DIRECT_NEAR_CALL_TAKEN",
   "PMC", 
   0x88,0x90,0,0}
, {"BR_INST_EXEC_DIRECT_NEAR_CALL_NON_TAKEN",
   "PMC", 
   0x88,0x50,0,0}
, {"BR_INST_EXEC_INDIRECT_NEAR_CALL_TAKEN",
   "PMC", 
   0x88,0xA0,0,0}
, {"BR_INST_EXEC_INDIRECT_NEAR_CALL_NON_TAKEN",
   "PMC", 
   0x88,0x60,0,0}
, {"BR_INST_EXEC_ALL_BRANCHES",
   "PMC", 
   0x88,0xFF,0,0}
, {"BR_MISP_EXEC_COND_TAKEN",
   "PMC", 
   0x89,0x81,0,0}
, {"BR_MISP_EXEC_COND_NON_TAKEN",
   "PMC", 
   0x89,0x41,0,0}
, {"BR_MISP_EXEC_INDIRECT_JMP_NON_CALL_RET_TAKEN",
   "PMC", 
   0x89,0x84,0,0}
, {"BR_MISP_EXEC_INDIRECT_JMP_NON_CALL_RET_NON_TAKEN",
   "PMC", 
   0x89,0x44,0,0}
, {"BR_MISP_EXEC_RETURN_NEAR_TAKEN",
   "PMC", 
   0x89,0x88,0,0}
, {"BR_MISP_EXEC_RETURN_NEAR_NON_TAKEN",
   "PMC", 
   0x89,0x48,0,0}
, {"BR_MISP_EXEC_DIRECT_NEAR_CALL_TAKEN",
   "PMC", 
   0x89,0x90,0,0}
, {"BR_MISP_EXEC_DIRECT_NEAR_CALL_NON_TAKEN",
   "PMC", 
   0x89,0x50,0,0}
, {"BR_MISP_EXEC_INDIRECT_NEAR_CALL_TAKEN",
   "PMC", 
   0x89,0xA0,0,0}
, {"BR_MISP_EXEC_INDIRECT_NEAR_CALL_NON_TAKEN",
   "PMC", 
   0x89,0x60,0,0}
, {"BR_MISP_EXEC_ALL_BRANCHES",
   "PMC", 
   0x89,0xFF,0,0}
, {"IDQ_UOPS_NOT_DELIVERED_CORE",
   "PMC", 
   0x9C,0x01,0,0}
, {"UOPS_DISPATCHED_PORT_PORT_0",
   "PMC", 
   0xA1,0x01,0,0}
, {"UOPS_DISPATCHED_PORT_PORT_1",
   "PMC", 
   0xA1,0x02,0,0}
, {"UOPS_DISPATCHED_PORT_PORT_2_LD",
   "PMC", 
   0xA1,0x04,0,0}
, {"UOPS_DISPATCHED_PORT_PORT_2_STA",
   "PMC", 
   0xA1,0x08,0,0}
, {"UOPS_DISPATCHED_PORT_PORT_2",
   "PMC", 
   0xA1,0x0C,0,0}
, {"UOPS_DISPATCHED_PORT_PORT_3_LD",
   "PMC", 
   0xA1,0x10,0,0}
, {"UOPS_DISPATCHED_PORT_PORT_3_STA",
   "PMC", 
   0xA1,0x20,0,0}
, {"UOPS_DISPATCHED_PORT_PORT_3",
   "PMC", 
   0xA1,0x30,0,0}
, {"UOPS_DISPATCHED_PORT_PORT_4",
   "PMC", 
   0xA1,0x40,0,0}
, {"UOPS_DISPATCHED_PORT_PORT_5",
   "PMC", 
   0xA1,0x80,0,0}
, {"RESOURCE_STALLS_ANY",
   "PMC", 
   0xA2,0x01,0,0}
, {"RESOURCE_STALLS_LB",
   "PMC", 
   0xA2,0x02,0,0}
, {"RESOURCE_STALLS_RS",
   "PMC", 
   0xA2,0x04,0,0}
, {"RESOURCE_STALLS_B",
   "PMC", 
   0xA2,0x08,0,0}
, {"RESOURCE_STALLS_ROB",
   "PMC", 
   0xA2,0x10,0,0}
, {"RESOURCE_STALLS_FCSW",
   "PMC", 
   0xA2,0x20,0,0}
, {"RESOURCE_STALLS_MXCSR",
   "PMC", 
   0xA2,0x40,0,0}
, {"RESOURCE_STALLS_OTHER",
   "PMC", 
   0xA2,0x80,0,0}
, {"DSB2MITE_SWITCHES_COUNT",
   "PMC", 
   0xAB,0x01,0,0}
, {"DSB2MITE_SWITCHES_PENALTY_CYCLES",
   "PMC", 
   0xAB,0x02,0,0}
, {"DSB_FILL_OTHER_CANCEL",
   "PMC", 
   0xAC,0x02,0,0}
, {"DSB_FILL_EXCEED_DSB_LINES",
   "PMC", 
   0xAC,0x08,0,0}
, {"DSB_FILL_ALL_CANCEL",
   "PMC", 
   0xAC,0x0A,0,0}
, {"ITLB_ITLB_FLUSH",
   "PMC", 
   0xAE,0x01,0,0}
, {"OFFCORE_REQUESTS_DEMAND_DATA_RD",
   "PMC", 
   0xB0,0x01,0,0}
, {"OFFCORE_REQUESTS_DEMAND_CODE_RD",
   "PMC", 
   0xB0,0x02,0,0}
, {"OFFCORE_REQUESTS_DEMAND_RFO",
   "PMC", 
   0xB0,0x04,0,0}
, {"OFFCORE_REQUESTS_ALL_DATA_RD",
   "PMC", 
   0xB0,0x08,0,0}
, {"UOPS_DISPATCHED_THREAD",
   "PMC", 
   0xB1,0x01,0,0}
, {"UOPS_DISPATCHED_CORE",
   "PMC", 
   0xB1,0x02,0,0}
, {"OFFCORE_REQUESTS_BUFFER_SQ_FULL",
   "PMC", 
   0xB2,0x01,0,0}
, {"AGU_BYPASS_CANCEL_COUNT",
   "PMC", 
   0xB6,0x01,0,0}
, {"TLB_FLUSH_DTLB_THREAD",
   "PMC", 
   0xBD,0x01,0,0}
, {"TLB_FLUSH_STLB_ANY",
   "PMC", 
   0xBD,0x20,0,0}
, {"L1D_BLOCKS_BANK_CONFLICT_CYCLES",
   "PMC", 
   0xBF,0x05,0x41,0x01}
, {"INST_RETIRED_ANY_P",
   "PMC0", 
   0xC0,0x00,0,0}
, {"INST_RETIRED_PREC_DIST",
   "PMC0", 
   0xC0,0x01,0,0}
, {"OTHER_ASSISTS_ITLB_MISS_RETIRED",
   "PMC", 
   0xC1,0x02,0,0}
, {"OTHER_ASSISTS_AVX_TO_SSE",
   "PMC", 
   0xC1,0x10,0,0}
, {"OTHER_ASSISTS_SSE_TO_AVX",
   "PMC", 
   0xC1,0x20,0,0}
, {"UOPS_RETIRED_ALL",
   "PMC", 
   0xC2,0x01,0,0}
, {"UOPS_RETIRED_RETIRE_SLOTS",
   "PMC", 
   0xC2,0x02,0,0}
, {"MACHINE_CLEARS_MEMORY_ORDERING",
   "PMC", 
   0xC3,0x02,0,0}
, {"MACHINE_CLEARS_SMC",
   "PMC", 
   0xC3,0x04,0,0}
, {"MACHINE_CLEARS_MASKMOV",
   "PMC", 
   0xC3,0x20,0,0}
, {"BR_INST_RETIRED_ALL_BRANCHES",
   "PMC", 
   0xC4,0x00,0,0}
, {"BR_INST_RETIRED_CONDITIONAL",
   "PMC", 
   0xC4,0x01,0,0}
, {"BR_INST_RETIRED_NEAR_CALL",
   "PMC", 
   0xC4,0x02,0,0}
, {"BR_INST_RETIRED_ALL_BRANCHES",
   "PMC", 
   0xC4,0x04,0,0}
, {"BR_INST_RETIRED_NEAR_RETURN",
   "PMC", 
   0xC4,0x08,0,0}
, {"BR_INST_RETIRED_NOT_TAKEN",
   "PMC", 
   0xC4,0x10,0,0}
, {"BR_INST_RETIRED_NEAR_TAKEN",
   "PMC", 
   0xC4,0x20,0,0}
, {"BR_INST_RETIRED_FAR_BRANCH",
   "PMC", 
   0xC4,0x40,0,0}
, {"BR_MISP_RETIRED_ALL_BRANCHES",
   "PMC", 
   0xC5,0x00,0,0}
, {"BR_MISP_RETIRED_CONDITIONAL",
   "PMC", 
   0xC5,0x01,0,0}
, {"BR_MISP_RETIRED_NEAR_CALL",
   "PMC", 
   0xC5,0x02,0,0}
, {"BR_MISP_RETIRED_ALL_BRANCHES",
   "PMC", 
   0xC5,0x04,0,0}
, {"BR_MISP_RETIRED_NOT_TAKEN",
   "PMC", 
   0xC5,0x10,0,0}
, {"BR_MISP_RETIRED_TAKEN",
   "PMC", 
   0xC5,0x20,0,0}
, {"FP_ASSIST_X87_OUTPUT",
   "PMC", 
   0xCA,0x02,0,0}
, {"FP_ASSIST_X87_INPUT",
   "PMC", 
   0xCA,0x04,0,0}
, {"FP_ASSIST_SIMD_OUTPUT",
   "PMC", 
   0xCA,0x08,0,0}
, {"FP_ASSIST_SIMD_INPUT",
   "PMC", 
   0xCA,0x10,0,0}
, {"FP_ASSIST_ANY",
   "PMC", 
   0xCA,0x1E,0,0}
, {"HW_INTERRUPTS_RECEIVED",
   "PMC", 
   0xCB,0x01,0,0}
, {"ROB_MISC_EVENT_LBR_INSERTS",
   "PMC", 
   0xCC,0x20,0,0}
, {"MEM_UOP_RETIRED_LOADS",
   "PMC", 
   0xD0,0x81,0,0}
, {"MEM_UOP_RETIRED_STORES",
   "PMC", 
   0xD0,0x82,0,0}
, {"MEM_UOP_RETIRED_LOADS_STLB_MISS",
   "PMC", 
   0xD0,0x11,0,0}
, {"MEM_UOP_RETIRED_STORES_STLB_MISS",
   "PMC", 
   0xD0,0x12,0,0}
, {"MEM_UOP_RETIRED_LOADS_LOCK",
   "PMC", 
   0xD0,0x21,0,0}
, {"MEM_UOP_RETIRED_STORES_LOCK",
   "PMC", 
   0xD0,0x22,0,0}
, {"MEM_UOP_RETIRED_LOADS_SPLIT",
   "PMC", 
   0xD0,0x41,0,0}
, {"MEM_UOP_RETIRED_STORES_SPLIT",
   "PMC", 
   0xD0,0x42,0,0}
, {"MEMLOAD_UOPS_RETIRED_L1_HIT",
   "PMC", 
   0xD1,0x01,0,0}
, {"MEMLOAD_UOPS_RETIRED_L2_HIT",
   "PMC", 
   0xD1,0x02,0,0}
, {"MEMLOAD_UOPS_RETIRED_LLC_HIT",
   "PMC", 
   0xD1,0x04,0,0}
, {"MEMLOAD_UOPS_RETIRED_HIT_LFB",
   "PMC", 
   0xD1,0x40,0,0}
, {"MEM_LOAD_UOPS_LLC_HIT_RETIRED_XSNP_MISS",
   "PMC", 
   0xD2,0x01,0,0}
, {"MEM_LOAD_UOPS_LLC_HIT_RETIRED_XSNP_HIT",
   "PMC", 
   0xD2,0x02,0,0}
, {"MEM_LOAD_UOPS_LLC_HIT_RETIRED_XSNP_HITM",
   "PMC", 
   0xD2,0x04,0,0}
, {"MEM_LOAD_UOPS_LLC_HIT_RETIRED_XSNP_NONE",
   "PMC", 
   0xD2,0x08,0,0}
, {"MEM_LOAD_UOPS_MISC_RETIRED_LLC_MISS",
   "PMC", 
   0xD4,0x02,0,0}
, {"L2_TRANS_DEMAND_DATA_RD",
   "PMC", 
   0xF0,0x01,0,0}
, {"L2_TRANS_RFO",
   "PMC", 
   0xF0,0x02,0,0}
, {"L2_TRANS_CODE_RD",
   "PMC", 
   0xF0,0x04,0,0}
, {"L2_TRANS_ALL_PREF",
   "PMC", 
   0xF0,0x08,0,0}
, {"L2_TRANS_L1D_WB",
   "PMC", 
   0xF0,0x10,0,0}
, {"L2_TRANS_L2_FILL",
   "PMC", 
   0xF0,0x20,0,0}
, {"L2_TRANS_L2_WB",
   "PMC", 
   0xF0,0x40,0,0}
, {"L2_TRANS_ALL_REQUESTS",
   "PMC", 
   0xF0,0x80,0,0}
, {"L2_LINES_IN_I",
   "PMC", 
   0xF1,0x01,0,0}
, {"L2_LINES_IN_S",
   "PMC", 
   0xF1,0x02,0,0}
, {"L2_LINES_IN_E",
   "PMC", 
   0xF1,0x04,0,0}
, {"L2_LINES_IN_ALL",
   "PMC", 
   0xF1,0x07,0,0}
, {"L2_LINES_OUT_DEMAND_CLEAN",
   "PMC", 
   0xF2,0x01,0,0}
, {"L2_LINES_OUT_DEMAND_DIRTY",
   "PMC", 
   0xF2,0x02,0,0}
, {"L2_LINES_OUT_PF_CLEAN",
   "PMC", 
   0xF2,0x04,0,0}
, {"L2_LINES_OUT_PF_DIRTY",
   "PMC", 
   0xF2,0x08,0,0}
, {"L2_LINES_OUT_DIRY_ALL",
   "PMC", 
   0xF2,0x0A,0,0}
, {"SQ_MISC_SPLIT_LOCK",
   "PMC", 
   0xF4,0x10,0,0}
};
