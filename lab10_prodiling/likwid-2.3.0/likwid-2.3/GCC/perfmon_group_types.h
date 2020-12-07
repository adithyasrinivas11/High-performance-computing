#ifndef PERFMON_GROUP_TYPES_H
#define PERFMON_GROUP_TYPES_H


typedef enum {
    _NOGROUP = 0,

    BRANCH,

    CACHE,

    CLOCK,

    CPI,

    DATA,

    ENERGY,

    FLOPS_AVX,

    FLOPS_DP,

    FLOPS_SP,

    FLOPS_X87,

    FPU_EXCEPTION,

    ICACHE,

    L2,

    L2CACHE,

    L3,

    L3CACHE,

    MEM,

    NUMA,

    NUMA2,

    SCHEDULER,

    TLB,

    VIEW,

    MAXNUMGROUPS
    } PerfmonGroup;

#endif
