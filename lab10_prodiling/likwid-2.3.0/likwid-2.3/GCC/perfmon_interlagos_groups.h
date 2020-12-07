/* GENERATED FILE: DO NOTE EDIT */

#define NUM_GROUPS_INTERLAGOS 13

static PerfmonGroupMap interlagos_group_map[NUM_GROUPS_INTERLAGOS] = {

    {"BRANCH",BRANCH,"Branch prediction miss rate/ratio","RETIRED_INSTRUCTIONS:PMC0,RETIRED_BRANCH_INSTR:PMC1,RETIRED_MISPREDICTED_BRANCH_INSTR:PMC2,RETIRED_TAKEN_BRANCH_INSTR:PMC3"},

    {"CACHE",CACHE,"Data cache miss rate/ratio","RETIRED_INSTRUCTIONS:PMC0,DATA_CACHE_ACCESSES:PMC1,DATA_CACHE_REFILLS_VALID:PMC2,DATA_CACHE_MISSES:PMC3"},

    {"CPI",CPI,"Cycles per instruction","RETIRED_INSTRUCTIONS:PMC0,CPU_CLOCKS_UNHALTED:PMC1,RETIRED_UOPS:PMC2"},

    {"DATA",DATA,"Load to store ratio","LS_DISPATCH_LOADS:PMC0,LS_DISPATCH_STORES:PMC1"},

    {"FLOPS_DP",FLOPS_DP,"Double Precision MFlops/s","RETIRED_INSTRUCTIONS:PMC0,CPU_CLOCKS_UNHALTED:PMC1,RETIRED_UOPS:PMC2,RETIRED_FLOPS_DOUBLE_ALL:PMC3"},

    {"FLOPS_SP",FLOPS_SP,"Single Precision MFlops/s","RETIRED_INSTRUCTIONS:PMC0,CPU_CLOCKS_UNHALTED:PMC1,RETIRED_UOPS:PMC2,RETIRED_FLOPS_SINGLE_ALL:PMC3"},

    {"FPU_EXCEPTION",FPU_EXCEPTION,"Floating point exceptions","RETIRED_INSTRUCTIONS:PMC0,RETIRED_FP_INSTRUCTIONS_ALL:PMC1,FPU_EXCEPTION_ALL:PMC2"},

    {"ICACHE",ICACHE,"Instruction cache miss rate/ratio","INSTRUCTION_CACHE_FETCHES:PMC0,INSTRUCTION_CACHE_L2_REFILLS:PMC1,INSTRUCTION_CACHE_SYSTEM_REFILLS:PMC2,RETIRED_INSTRUCTIONS:PMC3"},

    {"L2",L2,"L2 cache bandwidth in MBytes/s","DATA_CACHE_REFILLS_ALL:PMC0,DATA_CACHE_REFILLS_SYSTEM:PMC1,CPU_CLOCKS_UNHALTED:PMC2"},

    {"L2CACHE",L2CACHE,"L2 cache miss rate/ratio","RETIRED_INSTRUCTIONS:PMC0,REQUESTS_TO_L2_DC_FILL:PMC1,L2_CACHE_MISS_DC_FILL:PMC2"},

    {"L3",L3,"L3 cache bandwidth in MBytes/s","L2_FILL_WB_FILL:PMC0,L2_FILL_WB_WB:PMC1,CPU_CLOCKS_UNHALTED:PMC2"},

    {"MEM",MEM,"Main memory bandwidth in MBytes/s","UNC_DRAM_ACCESSES_ALL:UPMC0"},

    {"NUMA",NUMA,"Bandwidth on the Hypertransport links","CPU_TO_DRAM_LOCAL_TO_0:PMC0,CPU_TO_DRAM_LOCAL_TO_1:PMC1,CPU_TO_DRAM_LOCAL_TO_2:PMC2,CPU_TO_DRAM_LOCAL_TO_3:PMC3"},

};

void
perfmon_printDerivedMetricsInterlagos(PerfmonGroup group)
{
    int threadId;
    double time = rdtscTime;
    double inverseClock = 1.0 /(double) timer_getCpuClock();
    PerfmonResultTable tableData;
    int numRows;
    int numColumns = perfmon_numThreads;
    bstrList* fc;
    bstring label;
    double** stat;

    switch ( group ) 
    {

        case BRANCH:
            numRows = 6;
            stat = (double**) malloc(numRows * sizeof(double*));
            for (int i=0; i<numRows; i++)
            {
                stat[i] = (double*) malloc(4 * sizeof(double));
                stat[i][0] = 0;
                stat[i][1] = 0;
                stat[i][2] = DBL_MAX;
            }
            INIT_BASIC;

            bstrListAdd(fc,1,Branch rate  );

            bstrListAdd(fc,2,Branch misprediction rate );

            bstrListAdd(fc,3,Branch misprediction ratio );

            bstrListAdd(fc,4,Branch taken rate );

            bstrListAdd(fc,5,Branch taken ratio );

            bstrListAdd(fc,6,Instructions per branch );

            initResultTable(&tableData, fc, numRows, numColumns);

            for(threadId=0; threadId < perfmon_numThreads; threadId++)
            {

                tableData.rows[0].value[threadId] = perfmon_getResult(threadId,"PMC1")/perfmon_getResult(threadId,"PMC0");
                stat[0][0] += (double) tableData.rows[0].value[threadId];
                stat[0][1] =  MAX(stat[0][1],(double) tableData.rows[0].value[threadId]);
                stat[0][2] =  MIN(stat[0][2],(double) tableData.rows[0].value[threadId]);

                tableData.rows[1].value[threadId] = perfmon_getResult(threadId,"PMC2")/perfmon_getResult(threadId,"PMC0");
                stat[1][0] += (double) tableData.rows[1].value[threadId];
                stat[1][1] =  MAX(stat[1][1],(double) tableData.rows[1].value[threadId]);
                stat[1][2] =  MIN(stat[1][2],(double) tableData.rows[1].value[threadId]);

                tableData.rows[2].value[threadId] = perfmon_getResult(threadId,"PMC2")/perfmon_getResult(threadId,"PMC1");
                stat[2][0] += (double) tableData.rows[2].value[threadId];
                stat[2][1] =  MAX(stat[2][1],(double) tableData.rows[2].value[threadId]);
                stat[2][2] =  MIN(stat[2][2],(double) tableData.rows[2].value[threadId]);

                tableData.rows[3].value[threadId] = perfmon_getResult(threadId,"PMC3")/perfmon_getResult(threadId,"PMC0");
                stat[3][0] += (double) tableData.rows[3].value[threadId];
                stat[3][1] =  MAX(stat[3][1],(double) tableData.rows[3].value[threadId]);
                stat[3][2] =  MIN(stat[3][2],(double) tableData.rows[3].value[threadId]);

                tableData.rows[4].value[threadId] = perfmon_getResult(threadId,"PMC3")/perfmon_getResult(threadId,"PMC1");
                stat[4][0] += (double) tableData.rows[4].value[threadId];
                stat[4][1] =  MAX(stat[4][1],(double) tableData.rows[4].value[threadId]);
                stat[4][2] =  MIN(stat[4][2],(double) tableData.rows[4].value[threadId]);

                tableData.rows[5].value[threadId] = perfmon_getResult(threadId,"PMC0")/perfmon_getResult(threadId,"PMC1");
                stat[5][0] += (double) tableData.rows[5].value[threadId];
                stat[5][1] =  MAX(stat[5][1],(double) tableData.rows[5].value[threadId]);
                stat[5][2] =  MIN(stat[5][2],(double) tableData.rows[5].value[threadId]);

            }
            break;

        case CACHE:
            numRows = 4;
            stat = (double**) malloc(numRows * sizeof(double*));
            for (int i=0; i<numRows; i++)
            {
                stat[i] = (double*) malloc(4 * sizeof(double));
                stat[i][0] = 0;
                stat[i][1] = 0;
                stat[i][2] = DBL_MAX;
            }
            INIT_BASIC;

            bstrListAdd(fc,1,Data cache misses);

            bstrListAdd(fc,2,Data cache request rate);

            bstrListAdd(fc,3,Data cache miss rate);

            bstrListAdd(fc,4,Data cache miss ratio);

            initResultTable(&tableData, fc, numRows, numColumns);

            for(threadId=0; threadId < perfmon_numThreads; threadId++)
            {

                tableData.rows[0].value[threadId] = perfmon_getResult(threadId,"PMC3");
                stat[0][0] += (double) tableData.rows[0].value[threadId];
                stat[0][1] =  MAX(stat[0][1],(double) tableData.rows[0].value[threadId]);
                stat[0][2] =  MIN(stat[0][2],(double) tableData.rows[0].value[threadId]);

                tableData.rows[1].value[threadId] = perfmon_getResult(threadId,"PMC1")/perfmon_getResult(threadId,"PMC0");
                stat[1][0] += (double) tableData.rows[1].value[threadId];
                stat[1][1] =  MAX(stat[1][1],(double) tableData.rows[1].value[threadId]);
                stat[1][2] =  MIN(stat[1][2],(double) tableData.rows[1].value[threadId]);

                tableData.rows[2].value[threadId] = (perfmon_getResult(threadId,"PMC2"))/perfmon_getResult(threadId,"PMC0");
                stat[2][0] += (double) tableData.rows[2].value[threadId];
                stat[2][1] =  MAX(stat[2][1],(double) tableData.rows[2].value[threadId]);
                stat[2][2] =  MIN(stat[2][2],(double) tableData.rows[2].value[threadId]);

                tableData.rows[3].value[threadId] = (perfmon_getResult(threadId,"PMC2"))/perfmon_getResult(threadId,"PMC1");
                stat[3][0] += (double) tableData.rows[3].value[threadId];
                stat[3][1] =  MAX(stat[3][1],(double) tableData.rows[3].value[threadId]);
                stat[3][2] =  MIN(stat[3][2],(double) tableData.rows[3].value[threadId]);

            }
            break;

        case CPI:
            numRows = 4;
            stat = (double**) malloc(numRows * sizeof(double*));
            for (int i=0; i<numRows; i++)
            {
                stat[i] = (double*) malloc(4 * sizeof(double));
                stat[i][0] = 0;
                stat[i][1] = 0;
                stat[i][2] = DBL_MAX;
            }
            INIT_BASIC;

            bstrListAdd(fc,1,Runtime [s] );

            bstrListAdd(fc,2,CPI  );

            bstrListAdd(fc,3,CPI (based on uops)  );

            bstrListAdd(fc,4,IPC  );

            initResultTable(&tableData, fc, numRows, numColumns);

            for(threadId=0; threadId < perfmon_numThreads; threadId++)
            {

                tableData.rows[0].value[threadId] = perfmon_getResult(threadId,"PMC1")*inverseClock;
                stat[0][0] += (double) tableData.rows[0].value[threadId];
                stat[0][1] =  MAX(stat[0][1],(double) tableData.rows[0].value[threadId]);
                stat[0][2] =  MIN(stat[0][2],(double) tableData.rows[0].value[threadId]);

                tableData.rows[1].value[threadId] = perfmon_getResult(threadId,"PMC1")/perfmon_getResult(threadId,"PMC0");
                stat[1][0] += (double) tableData.rows[1].value[threadId];
                stat[1][1] =  MAX(stat[1][1],(double) tableData.rows[1].value[threadId]);
                stat[1][2] =  MIN(stat[1][2],(double) tableData.rows[1].value[threadId]);

                tableData.rows[2].value[threadId] = perfmon_getResult(threadId,"PMC1")/perfmon_getResult(threadId,"PMC2");
                stat[2][0] += (double) tableData.rows[2].value[threadId];
                stat[2][1] =  MAX(stat[2][1],(double) tableData.rows[2].value[threadId]);
                stat[2][2] =  MIN(stat[2][2],(double) tableData.rows[2].value[threadId]);

                tableData.rows[3].value[threadId] = perfmon_getResult(threadId,"PMC0")/perfmon_getResult(threadId,"PMC1");
                stat[3][0] += (double) tableData.rows[3].value[threadId];
                stat[3][1] =  MAX(stat[3][1],(double) tableData.rows[3].value[threadId]);
                stat[3][2] =  MIN(stat[3][2],(double) tableData.rows[3].value[threadId]);

            }
            break;

        case DATA:
            numRows = 1;
            stat = (double**) malloc(numRows * sizeof(double*));
            for (int i=0; i<numRows; i++)
            {
                stat[i] = (double*) malloc(4 * sizeof(double));
                stat[i][0] = 0;
                stat[i][1] = 0;
                stat[i][2] = DBL_MAX;
            }
            INIT_BASIC;

            bstrListAdd(fc,1,Load to Store ratio);

            initResultTable(&tableData, fc, numRows, numColumns);

            for(threadId=0; threadId < perfmon_numThreads; threadId++)
            {

                tableData.rows[0].value[threadId] = perfmon_getResult(threadId,"PMC0")/perfmon_getResult(threadId,"PMC1");
                stat[0][0] += (double) tableData.rows[0].value[threadId];
                stat[0][1] =  MAX(stat[0][1],(double) tableData.rows[0].value[threadId]);
                stat[0][2] =  MIN(stat[0][2],(double) tableData.rows[0].value[threadId]);

            }
            break;

        case FLOPS_DP:
            numRows = 5;
            stat = (double**) malloc(numRows * sizeof(double*));
            for (int i=0; i<numRows; i++)
            {
                stat[i] = (double*) malloc(4 * sizeof(double));
                stat[i][0] = 0;
                stat[i][1] = 0;
                stat[i][2] = DBL_MAX;
            }
            INIT_BASIC;

            bstrListAdd(fc,1,Runtime [s]);

            bstrListAdd(fc,2,MFlops/s   );

            bstrListAdd(fc,3,CPI  );

            bstrListAdd(fc,4,CPI (based on uops)  );

            bstrListAdd(fc,5,IPC  );

            initResultTable(&tableData, fc, numRows, numColumns);

            for(threadId=0; threadId < perfmon_numThreads; threadId++)
            {

                tableData.rows[0].value[threadId] = perfmon_getResult(threadId,"PMC1")*inverseClock;
                stat[0][0] += (double) tableData.rows[0].value[threadId];
                stat[0][1] =  MAX(stat[0][1],(double) tableData.rows[0].value[threadId]);
                stat[0][2] =  MIN(stat[0][2],(double) tableData.rows[0].value[threadId]);

                tableData.rows[1].value[threadId] = 1.0E-06*(perfmon_getResult(threadId,"PMC3"))/time;
                stat[1][0] += (double) tableData.rows[1].value[threadId];
                stat[1][1] =  MAX(stat[1][1],(double) tableData.rows[1].value[threadId]);
                stat[1][2] =  MIN(stat[1][2],(double) tableData.rows[1].value[threadId]);

                tableData.rows[2].value[threadId] = perfmon_getResult(threadId,"PMC1")/perfmon_getResult(threadId,"PMC0");
                stat[2][0] += (double) tableData.rows[2].value[threadId];
                stat[2][1] =  MAX(stat[2][1],(double) tableData.rows[2].value[threadId]);
                stat[2][2] =  MIN(stat[2][2],(double) tableData.rows[2].value[threadId]);

                tableData.rows[3].value[threadId] = perfmon_getResult(threadId,"PMC1")/perfmon_getResult(threadId,"PMC2");
                stat[3][0] += (double) tableData.rows[3].value[threadId];
                stat[3][1] =  MAX(stat[3][1],(double) tableData.rows[3].value[threadId]);
                stat[3][2] =  MIN(stat[3][2],(double) tableData.rows[3].value[threadId]);

                tableData.rows[4].value[threadId] = perfmon_getResult(threadId,"PMC0")/perfmon_getResult(threadId,"PMC1");
                stat[4][0] += (double) tableData.rows[4].value[threadId];
                stat[4][1] =  MAX(stat[4][1],(double) tableData.rows[4].value[threadId]);
                stat[4][2] =  MIN(stat[4][2],(double) tableData.rows[4].value[threadId]);

            }
            break;

        case FLOPS_SP:
            numRows = 5;
            stat = (double**) malloc(numRows * sizeof(double*));
            for (int i=0; i<numRows; i++)
            {
                stat[i] = (double*) malloc(4 * sizeof(double));
                stat[i][0] = 0;
                stat[i][1] = 0;
                stat[i][2] = DBL_MAX;
            }
            INIT_BASIC;

            bstrListAdd(fc,1,Runtime [s]);

            bstrListAdd(fc,2,MFlops/s   );

            bstrListAdd(fc,3,CPI  );

            bstrListAdd(fc,4,CPI (based on uops)  );

            bstrListAdd(fc,5,IPC  );

            initResultTable(&tableData, fc, numRows, numColumns);

            for(threadId=0; threadId < perfmon_numThreads; threadId++)
            {

                tableData.rows[0].value[threadId] = perfmon_getResult(threadId,"PMC1")*inverseClock;
                stat[0][0] += (double) tableData.rows[0].value[threadId];
                stat[0][1] =  MAX(stat[0][1],(double) tableData.rows[0].value[threadId]);
                stat[0][2] =  MIN(stat[0][2],(double) tableData.rows[0].value[threadId]);

                tableData.rows[1].value[threadId] = 1.0E-06*(perfmon_getResult(threadId,"PMC3"))/time;
                stat[1][0] += (double) tableData.rows[1].value[threadId];
                stat[1][1] =  MAX(stat[1][1],(double) tableData.rows[1].value[threadId]);
                stat[1][2] =  MIN(stat[1][2],(double) tableData.rows[1].value[threadId]);

                tableData.rows[2].value[threadId] = perfmon_getResult(threadId,"PMC1")/perfmon_getResult(threadId,"PMC0");
                stat[2][0] += (double) tableData.rows[2].value[threadId];
                stat[2][1] =  MAX(stat[2][1],(double) tableData.rows[2].value[threadId]);
                stat[2][2] =  MIN(stat[2][2],(double) tableData.rows[2].value[threadId]);

                tableData.rows[3].value[threadId] = perfmon_getResult(threadId,"PMC1")/perfmon_getResult(threadId,"PMC2");
                stat[3][0] += (double) tableData.rows[3].value[threadId];
                stat[3][1] =  MAX(stat[3][1],(double) tableData.rows[3].value[threadId]);
                stat[3][2] =  MIN(stat[3][2],(double) tableData.rows[3].value[threadId]);

                tableData.rows[4].value[threadId] = perfmon_getResult(threadId,"PMC0")/perfmon_getResult(threadId,"PMC1");
                stat[4][0] += (double) tableData.rows[4].value[threadId];
                stat[4][1] =  MAX(stat[4][1],(double) tableData.rows[4].value[threadId]);
                stat[4][2] =  MIN(stat[4][2],(double) tableData.rows[4].value[threadId]);

            }
            break;

        case FPU_EXCEPTION:
            numRows = 2;
            stat = (double**) malloc(numRows * sizeof(double*));
            for (int i=0; i<numRows; i++)
            {
                stat[i] = (double*) malloc(4 * sizeof(double));
                stat[i][0] = 0;
                stat[i][1] = 0;
                stat[i][2] = DBL_MAX;
            }
            INIT_BASIC;

            bstrListAdd(fc,1,Overall FP exception rate );

            bstrListAdd(fc,2,FP exception rate   );

            initResultTable(&tableData, fc, numRows, numColumns);

            for(threadId=0; threadId < perfmon_numThreads; threadId++)
            {

                tableData.rows[0].value[threadId] = perfmon_getResult(threadId,"PMC2")/perfmon_getResult(threadId,"PMC0");
                stat[0][0] += (double) tableData.rows[0].value[threadId];
                stat[0][1] =  MAX(stat[0][1],(double) tableData.rows[0].value[threadId]);
                stat[0][2] =  MIN(stat[0][2],(double) tableData.rows[0].value[threadId]);

                tableData.rows[1].value[threadId] = perfmon_getResult(threadId,"PMC2")/perfmon_getResult(threadId,"PMC1");
                stat[1][0] += (double) tableData.rows[1].value[threadId];
                stat[1][1] =  MAX(stat[1][1],(double) tableData.rows[1].value[threadId]);
                stat[1][2] =  MIN(stat[1][2],(double) tableData.rows[1].value[threadId]);

            }
            break;

        case ICACHE:
            numRows = 4;
            stat = (double**) malloc(numRows * sizeof(double*));
            for (int i=0; i<numRows; i++)
            {
                stat[i] = (double*) malloc(4 * sizeof(double));
                stat[i][0] = 0;
                stat[i][1] = 0;
                stat[i][2] = DBL_MAX;
            }
            INIT_BASIC;

            bstrListAdd(fc,1,Instruction cache misses );

            bstrListAdd(fc,2,Instruction cache request rate  );

            bstrListAdd(fc,3,Instruction cache miss rate   );

            bstrListAdd(fc,4,Instruction cache miss ratio  );

            initResultTable(&tableData, fc, numRows, numColumns);

            for(threadId=0; threadId < perfmon_numThreads; threadId++)
            {

                tableData.rows[0].value[threadId] = perfmon_getResult(threadId,"PMC1")+perfmon_getResult(threadId,"PMC2");
                stat[0][0] += (double) tableData.rows[0].value[threadId];
                stat[0][1] =  MAX(stat[0][1],(double) tableData.rows[0].value[threadId]);
                stat[0][2] =  MIN(stat[0][2],(double) tableData.rows[0].value[threadId]);

                tableData.rows[1].value[threadId] = perfmon_getResult(threadId,"PMC0")/perfmon_getResult(threadId,"PMC3");
                stat[1][0] += (double) tableData.rows[1].value[threadId];
                stat[1][1] =  MAX(stat[1][1],(double) tableData.rows[1].value[threadId]);
                stat[1][2] =  MIN(stat[1][2],(double) tableData.rows[1].value[threadId]);

                tableData.rows[2].value[threadId] = (perfmon_getResult(threadId,"PMC1")+perfmon_getResult(threadId,"PMC2"))/perfmon_getResult(threadId,"PMC3");
                stat[2][0] += (double) tableData.rows[2].value[threadId];
                stat[2][1] =  MAX(stat[2][1],(double) tableData.rows[2].value[threadId]);
                stat[2][2] =  MIN(stat[2][2],(double) tableData.rows[2].value[threadId]);

                tableData.rows[3].value[threadId] = (perfmon_getResult(threadId,"PMC1")+perfmon_getResult(threadId,"PMC2"))/perfmon_getResult(threadId,"PMC0");
                stat[3][0] += (double) tableData.rows[3].value[threadId];
                stat[3][1] =  MAX(stat[3][1],(double) tableData.rows[3].value[threadId]);
                stat[3][2] =  MIN(stat[3][2],(double) tableData.rows[3].value[threadId]);

            }
            break;

        case L2:
            numRows = 4;
            stat = (double**) malloc(numRows * sizeof(double*));
            for (int i=0; i<numRows; i++)
            {
                stat[i] = (double*) malloc(4 * sizeof(double));
                stat[i][0] = 0;
                stat[i][1] = 0;
                stat[i][2] = DBL_MAX;
            }
            INIT_BASIC;

            bstrListAdd(fc,1,Runtime [s]  );

            bstrListAdd(fc,2,L2 bandwidth [MBytes/s]  );

            bstrListAdd(fc,3,Cache refill bandwidth System/L2 MBytes/s  );

            bstrListAdd(fc,4,Cache refill bandwidth System  MBytes/s   );

            initResultTable(&tableData, fc, numRows, numColumns);

            for(threadId=0; threadId < perfmon_numThreads; threadId++)
            {

                tableData.rows[0].value[threadId] = perfmon_getResult(threadId,"PMC2")*inverseClock;
                stat[0][0] += (double) tableData.rows[0].value[threadId];
                stat[0][1] =  MAX(stat[0][1],(double) tableData.rows[0].value[threadId]);
                stat[0][2] =  MIN(stat[0][2],(double) tableData.rows[0].value[threadId]);

                tableData.rows[1].value[threadId] = 1.0E-06*(perfmon_getResult(threadId,"PMC0")-perfmon_getResult(threadId,"PMC1"))*64.0/time;
                stat[1][0] += (double) tableData.rows[1].value[threadId];
                stat[1][1] =  MAX(stat[1][1],(double) tableData.rows[1].value[threadId]);
                stat[1][2] =  MIN(stat[1][2],(double) tableData.rows[1].value[threadId]);

                tableData.rows[2].value[threadId] = 1.0E-06*perfmon_getResult(threadId,"PMC0")*64.0/time;
                stat[2][0] += (double) tableData.rows[2].value[threadId];
                stat[2][1] =  MAX(stat[2][1],(double) tableData.rows[2].value[threadId]);
                stat[2][2] =  MIN(stat[2][2],(double) tableData.rows[2].value[threadId]);

                tableData.rows[3].value[threadId] = 1.0E-06*perfmon_getResult(threadId,"PMC1")*64.0/time;
                stat[3][0] += (double) tableData.rows[3].value[threadId];
                stat[3][1] =  MAX(stat[3][1],(double) tableData.rows[3].value[threadId]);
                stat[3][2] =  MIN(stat[3][2],(double) tableData.rows[3].value[threadId]);

            }
            break;

        case L2CACHE:
            numRows = 3;
            stat = (double**) malloc(numRows * sizeof(double*));
            for (int i=0; i<numRows; i++)
            {
                stat[i] = (double*) malloc(4 * sizeof(double));
                stat[i][0] = 0;
                stat[i][1] = 0;
                stat[i][2] = DBL_MAX;
            }
            INIT_BASIC;

            bstrListAdd(fc,1,L2 request rate  );

            bstrListAdd(fc,2,L2 miss rate  );

            bstrListAdd(fc,3,L2 miss ratio  );

            initResultTable(&tableData, fc, numRows, numColumns);

            for(threadId=0; threadId < perfmon_numThreads; threadId++)
            {

                tableData.rows[0].value[threadId] = (perfmon_getResult(threadId,"PMC1"))/perfmon_getResult(threadId,"PMC0");
                stat[0][0] += (double) tableData.rows[0].value[threadId];
                stat[0][1] =  MAX(stat[0][1],(double) tableData.rows[0].value[threadId]);
                stat[0][2] =  MIN(stat[0][2],(double) tableData.rows[0].value[threadId]);

                tableData.rows[1].value[threadId] = perfmon_getResult(threadId,"PMC2")/perfmon_getResult(threadId,"PMC0");
                stat[1][0] += (double) tableData.rows[1].value[threadId];
                stat[1][1] =  MAX(stat[1][1],(double) tableData.rows[1].value[threadId]);
                stat[1][2] =  MIN(stat[1][2],(double) tableData.rows[1].value[threadId]);

                tableData.rows[2].value[threadId] = perfmon_getResult(threadId,"PMC2")/(perfmon_getResult(threadId,"PMC1"));
                stat[2][0] += (double) tableData.rows[2].value[threadId];
                stat[2][1] =  MAX(stat[2][1],(double) tableData.rows[2].value[threadId]);
                stat[2][2] =  MIN(stat[2][2],(double) tableData.rows[2].value[threadId]);

            }
            break;

        case L3:
            numRows = 4;
            stat = (double**) malloc(numRows * sizeof(double*));
            for (int i=0; i<numRows; i++)
            {
                stat[i] = (double*) malloc(4 * sizeof(double));
                stat[i][0] = 0;
                stat[i][1] = 0;
                stat[i][2] = DBL_MAX;
            }
            INIT_BASIC;

            bstrListAdd(fc,1,Runtime [s]  );

            bstrListAdd(fc,2,L3 bandwidth [MBytes/s]  );

            bstrListAdd(fc,3,L3 refill bandwidth MBytes/s  );

            bstrListAdd(fc,4,L3 evict MBytes/s   );

            initResultTable(&tableData, fc, numRows, numColumns);

            for(threadId=0; threadId < perfmon_numThreads; threadId++)
            {

                tableData.rows[0].value[threadId] = perfmon_getResult(threadId,"PMC2")*inverseClock;
                stat[0][0] += (double) tableData.rows[0].value[threadId];
                stat[0][1] =  MAX(stat[0][1],(double) tableData.rows[0].value[threadId]);
                stat[0][2] =  MIN(stat[0][2],(double) tableData.rows[0].value[threadId]);

                tableData.rows[1].value[threadId] = 1.0E-06*(perfmon_getResult(threadId,"PMC0")+perfmon_getResult(threadId,"PMC1"))*64.0/time;
                stat[1][0] += (double) tableData.rows[1].value[threadId];
                stat[1][1] =  MAX(stat[1][1],(double) tableData.rows[1].value[threadId]);
                stat[1][2] =  MIN(stat[1][2],(double) tableData.rows[1].value[threadId]);

                tableData.rows[2].value[threadId] = 1.0E-06*perfmon_getResult(threadId,"PMC0")*64.0/time;
                stat[2][0] += (double) tableData.rows[2].value[threadId];
                stat[2][1] =  MAX(stat[2][1],(double) tableData.rows[2].value[threadId]);
                stat[2][2] =  MIN(stat[2][2],(double) tableData.rows[2].value[threadId]);

                tableData.rows[3].value[threadId] = 1.0E-06*perfmon_getResult(threadId,"PMC1")*64.0/time;
                stat[3][0] += (double) tableData.rows[3].value[threadId];
                stat[3][1] =  MAX(stat[3][1],(double) tableData.rows[3].value[threadId]);
                stat[3][2] =  MIN(stat[3][2],(double) tableData.rows[3].value[threadId]);

            }
            break;

        case MEM:
            numRows = 3;
            stat = (double**) malloc(numRows * sizeof(double*));
            for (int i=0; i<numRows; i++)
            {
                stat[i] = (double*) malloc(4 * sizeof(double));
                stat[i][0] = 0;
                stat[i][1] = 0;
                stat[i][2] = DBL_MAX;
            }
            INIT_BASIC;

            bstrListAdd(fc,1,Read data bandwidth (MBytes/s) );

            bstrListAdd(fc,2,Write data bandwidth (MBytes/s) );

            bstrListAdd(fc,3,DRAM bandwidth (MBytes/s)  );

            initResultTable(&tableData, fc, numRows, numColumns);

            for(threadId=0; threadId < perfmon_numThreads; threadId++)
            {

                tableData.rows[0].value[threadId] = 1.0E-06*perfmon_getResult(threadId,"UPMC0")*64.0/time;
                stat[0][0] += (double) tableData.rows[0].value[threadId];
                stat[0][1] =  MAX(stat[0][1],(double) tableData.rows[0].value[threadId]);
                stat[0][2] =  MIN(stat[0][2],(double) tableData.rows[0].value[threadId]);

                tableData.rows[1].value[threadId] = 1.0E-06*perfmon_getResult(threadId,"UPMC0")*8.0/time;
                stat[1][0] += (double) tableData.rows[1].value[threadId];
                stat[1][1] =  MAX(stat[1][1],(double) tableData.rows[1].value[threadId]);
                stat[1][2] =  MIN(stat[1][2],(double) tableData.rows[1].value[threadId]);

                tableData.rows[2].value[threadId] = 1.0E-06*(perfmon_getResult(threadId,"UPMC0"))*64.0/time;
                stat[2][0] += (double) tableData.rows[2].value[threadId];
                stat[2][1] =  MAX(stat[2][1],(double) tableData.rows[2].value[threadId]);
                stat[2][2] =  MIN(stat[2][2],(double) tableData.rows[2].value[threadId]);

            }
            break;

        case NUMA:
            numRows = 4;
            stat = (double**) malloc(numRows * sizeof(double*));
            for (int i=0; i<numRows; i++)
            {
                stat[i] = (double*) malloc(4 * sizeof(double));
                stat[i][0] = 0;
                stat[i][1] = 0;
                stat[i][2] = DBL_MAX;
            }
            INIT_BASIC;

            bstrListAdd(fc,1,Mega requests per second to Node 0  );

            bstrListAdd(fc,2,Mega requests per second to Node 1  );

            bstrListAdd(fc,3,Mega requests per second to Node 2  );

            bstrListAdd(fc,4,Mega requests per second to Node 3  );

            initResultTable(&tableData, fc, numRows, numColumns);

            for(threadId=0; threadId < perfmon_numThreads; threadId++)
            {

                tableData.rows[0].value[threadId] = 1.0E-06*perfmon_getResult(threadId,"PMC0")/time;
                stat[0][0] += (double) tableData.rows[0].value[threadId];
                stat[0][1] =  MAX(stat[0][1],(double) tableData.rows[0].value[threadId]);
                stat[0][2] =  MIN(stat[0][2],(double) tableData.rows[0].value[threadId]);

                tableData.rows[1].value[threadId] = 1.0E-06*perfmon_getResult(threadId,"PMC1")/time;
                stat[1][0] += (double) tableData.rows[1].value[threadId];
                stat[1][1] =  MAX(stat[1][1],(double) tableData.rows[1].value[threadId]);
                stat[1][2] =  MIN(stat[1][2],(double) tableData.rows[1].value[threadId]);

                tableData.rows[2].value[threadId] = 1.0E-06*perfmon_getResult(threadId,"PMC2")/time;
                stat[2][0] += (double) tableData.rows[2].value[threadId];
                stat[2][1] =  MAX(stat[2][1],(double) tableData.rows[2].value[threadId]);
                stat[2][2] =  MIN(stat[2][2],(double) tableData.rows[2].value[threadId]);

                tableData.rows[3].value[threadId] = 1.0E-06*perfmon_getResult(threadId,"PMC3")/time;
                stat[3][0] += (double) tableData.rows[3].value[threadId];
                stat[3][1] =  MAX(stat[3][1],(double) tableData.rows[3].value[threadId]);
                stat[3][2] =  MIN(stat[3][2],(double) tableData.rows[3].value[threadId]);

            }
            break;


        default:
            fprintf (stderr, "perfmon_printDerivedMetricsinterlagos: Unknown group! Exiting!\n" );
            exit (EXIT_FAILURE);
            break;
    }

    printResultTable(&tableData);
    freeResultTable(&tableData);



    /* for threaded results print sum, max, min and avg */
    if (perfmon_numThreads > 1)
    {
        initStatisticTable(&tableData, fc, numRows);
        for (int i=0; i<numRows; i++)
        {
            stat[i][3] =  stat[i][0]/perfmon_numThreads;
            for (int j=0; j<4; j++)
            {
                tableData.rows[i].value[j] = stat[i][j];
            }
        }
        printResultTable(&tableData);
        freeResultTable(&tableData);
    }

    for (int i=0; i<numRows; i++)
    {
        free(stat[i]);
    }
    free(stat);
    bdestroy(label);
    bstrListDestroy(fc);
}

void
perfmon_logDerivedMetricsInterlagos(PerfmonGroup group, double time,double timeStamp)
{
    int threadId;
    double inverseClock = 1.0 /(double) timer_getCpuClock();

    switch ( group ) 
    {
        
        case BRANCH:

                    
                        printf("Branch rate   %e ",timeStamp);
                        for(threadId=0; threadId < perfmon_numThreads; threadId++)
                        {
                            printf(" %e  ",perfmon_getResult(threadId,"PMC1")/perfmon_getResult(threadId,"PMC0"));
                        }
                        printf("\n");
                    
                        printf("Branch misprediction rate  %e ",timeStamp);
                        for(threadId=0; threadId < perfmon_numThreads; threadId++)
                        {
                            printf(" %e  ",perfmon_getResult(threadId,"PMC2")/perfmon_getResult(threadId,"PMC0"));
                        }
                        printf("\n");
                    
                        printf("Branch misprediction ratio  %e ",timeStamp);
                        for(threadId=0; threadId < perfmon_numThreads; threadId++)
                        {
                            printf(" %e  ",perfmon_getResult(threadId,"PMC2")/perfmon_getResult(threadId,"PMC1"));
                        }
                        printf("\n");
                    
                        printf("Branch taken rate  %e ",timeStamp);
                        for(threadId=0; threadId < perfmon_numThreads; threadId++)
                        {
                            printf(" %e  ",perfmon_getResult(threadId,"PMC3")/perfmon_getResult(threadId,"PMC0"));
                        }
                        printf("\n");
                    
                        printf("Branch taken ratio  %e ",timeStamp);
                        for(threadId=0; threadId < perfmon_numThreads; threadId++)
                        {
                            printf(" %e  ",perfmon_getResult(threadId,"PMC3")/perfmon_getResult(threadId,"PMC1"));
                        }
                        printf("\n");
                    
                        printf("Instructions per branch  %e ",timeStamp);
                        for(threadId=0; threadId < perfmon_numThreads; threadId++)
                        {
                            printf(" %e  ",perfmon_getResult(threadId,"PMC0")/perfmon_getResult(threadId,"PMC1"));
                        }
                        printf("\n");
                    
            break;
            
        case CACHE:

                    
                        printf("Data cache misses %e ",timeStamp);
                        for(threadId=0; threadId < perfmon_numThreads; threadId++)
                        {
                            printf(" %e  ",perfmon_getResult(threadId,"PMC3"));
                        }
                        printf("\n");
                    
                        printf("Data cache request rate %e ",timeStamp);
                        for(threadId=0; threadId < perfmon_numThreads; threadId++)
                        {
                            printf(" %e  ",perfmon_getResult(threadId,"PMC1")/perfmon_getResult(threadId,"PMC0"));
                        }
                        printf("\n");
                    
                        printf("Data cache miss rate %e ",timeStamp);
                        for(threadId=0; threadId < perfmon_numThreads; threadId++)
                        {
                            printf(" %e  ",(perfmon_getResult(threadId,"PMC2"))/perfmon_getResult(threadId,"PMC0"));
                        }
                        printf("\n");
                    
                        printf("Data cache miss ratio %e ",timeStamp);
                        for(threadId=0; threadId < perfmon_numThreads; threadId++)
                        {
                            printf(" %e  ",(perfmon_getResult(threadId,"PMC2"))/perfmon_getResult(threadId,"PMC1"));
                        }
                        printf("\n");
                    
            break;
            
        case CPI:

                    
                        printf("Runtime [s]  %e ",timeStamp);
                        for(threadId=0; threadId < perfmon_numThreads; threadId++)
                        {
                            printf(" %e  ",perfmon_getResult(threadId,"PMC1")*inverseClock);
                        }
                        printf("\n");
                    
                        printf("CPI   %e ",timeStamp);
                        for(threadId=0; threadId < perfmon_numThreads; threadId++)
                        {
                            printf(" %e  ",perfmon_getResult(threadId,"PMC1")/perfmon_getResult(threadId,"PMC0"));
                        }
                        printf("\n");
                    
                        printf("CPI (based on uops)   %e ",timeStamp);
                        for(threadId=0; threadId < perfmon_numThreads; threadId++)
                        {
                            printf(" %e  ",perfmon_getResult(threadId,"PMC1")/perfmon_getResult(threadId,"PMC2"));
                        }
                        printf("\n");
                    
                        printf("IPC   %e ",timeStamp);
                        for(threadId=0; threadId < perfmon_numThreads; threadId++)
                        {
                            printf(" %e  ",perfmon_getResult(threadId,"PMC0")/perfmon_getResult(threadId,"PMC1"));
                        }
                        printf("\n");
                    
            break;
            
        case DATA:

                    
                        printf("Load to Store ratio %e ",timeStamp);
                        for(threadId=0; threadId < perfmon_numThreads; threadId++)
                        {
                            printf(" %e  ",perfmon_getResult(threadId,"PMC0")/perfmon_getResult(threadId,"PMC1"));
                        }
                        printf("\n");
                    
            break;
            
        case FLOPS_DP:

                    
                        printf("Runtime [s] %e ",timeStamp);
                        for(threadId=0; threadId < perfmon_numThreads; threadId++)
                        {
                            printf(" %e  ",perfmon_getResult(threadId,"PMC1")*inverseClock);
                        }
                        printf("\n");
                    
                        printf("MFlops/s    %e ",timeStamp);
                        for(threadId=0; threadId < perfmon_numThreads; threadId++)
                        {
                            printf(" %e  ",1.0E-06*(perfmon_getResult(threadId,"PMC3"))/time);
                        }
                        printf("\n");
                    
                        printf("CPI   %e ",timeStamp);
                        for(threadId=0; threadId < perfmon_numThreads; threadId++)
                        {
                            printf(" %e  ",perfmon_getResult(threadId,"PMC1")/perfmon_getResult(threadId,"PMC0"));
                        }
                        printf("\n");
                    
                        printf("CPI (based on uops)   %e ",timeStamp);
                        for(threadId=0; threadId < perfmon_numThreads; threadId++)
                        {
                            printf(" %e  ",perfmon_getResult(threadId,"PMC1")/perfmon_getResult(threadId,"PMC2"));
                        }
                        printf("\n");
                    
                        printf("IPC   %e ",timeStamp);
                        for(threadId=0; threadId < perfmon_numThreads; threadId++)
                        {
                            printf(" %e  ",perfmon_getResult(threadId,"PMC0")/perfmon_getResult(threadId,"PMC1"));
                        }
                        printf("\n");
                    
            break;
            
        case FLOPS_SP:

                    
                        printf("Runtime [s] %e ",timeStamp);
                        for(threadId=0; threadId < perfmon_numThreads; threadId++)
                        {
                            printf(" %e  ",perfmon_getResult(threadId,"PMC1")*inverseClock);
                        }
                        printf("\n");
                    
                        printf("MFlops/s    %e ",timeStamp);
                        for(threadId=0; threadId < perfmon_numThreads; threadId++)
                        {
                            printf(" %e  ",1.0E-06*(perfmon_getResult(threadId,"PMC3"))/time);
                        }
                        printf("\n");
                    
                        printf("CPI   %e ",timeStamp);
                        for(threadId=0; threadId < perfmon_numThreads; threadId++)
                        {
                            printf(" %e  ",perfmon_getResult(threadId,"PMC1")/perfmon_getResult(threadId,"PMC0"));
                        }
                        printf("\n");
                    
                        printf("CPI (based on uops)   %e ",timeStamp);
                        for(threadId=0; threadId < perfmon_numThreads; threadId++)
                        {
                            printf(" %e  ",perfmon_getResult(threadId,"PMC1")/perfmon_getResult(threadId,"PMC2"));
                        }
                        printf("\n");
                    
                        printf("IPC   %e ",timeStamp);
                        for(threadId=0; threadId < perfmon_numThreads; threadId++)
                        {
                            printf(" %e  ",perfmon_getResult(threadId,"PMC0")/perfmon_getResult(threadId,"PMC1"));
                        }
                        printf("\n");
                    
            break;
            
        case FPU_EXCEPTION:

                    
                        printf("Overall FP exception rate  %e ",timeStamp);
                        for(threadId=0; threadId < perfmon_numThreads; threadId++)
                        {
                            printf(" %e  ",perfmon_getResult(threadId,"PMC2")/perfmon_getResult(threadId,"PMC0"));
                        }
                        printf("\n");
                    
                        printf("FP exception rate    %e ",timeStamp);
                        for(threadId=0; threadId < perfmon_numThreads; threadId++)
                        {
                            printf(" %e  ",perfmon_getResult(threadId,"PMC2")/perfmon_getResult(threadId,"PMC1"));
                        }
                        printf("\n");
                    
            break;
            
        case ICACHE:

                    
                        printf("Instruction cache misses  %e ",timeStamp);
                        for(threadId=0; threadId < perfmon_numThreads; threadId++)
                        {
                            printf(" %e  ",perfmon_getResult(threadId,"PMC1")+perfmon_getResult(threadId,"PMC2"));
                        }
                        printf("\n");
                    
                        printf("Instruction cache request rate   %e ",timeStamp);
                        for(threadId=0; threadId < perfmon_numThreads; threadId++)
                        {
                            printf(" %e  ",perfmon_getResult(threadId,"PMC0")/perfmon_getResult(threadId,"PMC3"));
                        }
                        printf("\n");
                    
                        printf("Instruction cache miss rate    %e ",timeStamp);
                        for(threadId=0; threadId < perfmon_numThreads; threadId++)
                        {
                            printf(" %e  ",(perfmon_getResult(threadId,"PMC1")+perfmon_getResult(threadId,"PMC2"))/perfmon_getResult(threadId,"PMC3"));
                        }
                        printf("\n");
                    
                        printf("Instruction cache miss ratio   %e ",timeStamp);
                        for(threadId=0; threadId < perfmon_numThreads; threadId++)
                        {
                            printf(" %e  ",(perfmon_getResult(threadId,"PMC1")+perfmon_getResult(threadId,"PMC2"))/perfmon_getResult(threadId,"PMC0"));
                        }
                        printf("\n");
                    
            break;
            
        case L2:

                    
                        printf("Runtime [s]   %e ",timeStamp);
                        for(threadId=0; threadId < perfmon_numThreads; threadId++)
                        {
                            printf(" %e  ",perfmon_getResult(threadId,"PMC2")*inverseClock);
                        }
                        printf("\n");
                    
                        printf("L2 bandwidth [MBytes/s]   %e ",timeStamp);
                        for(threadId=0; threadId < perfmon_numThreads; threadId++)
                        {
                            printf(" %e  ",1.0E-06*(perfmon_getResult(threadId,"PMC0")-perfmon_getResult(threadId,"PMC1"))*64.0/time);
                        }
                        printf("\n");
                    
                        printf("Cache refill bandwidth System/L2 MBytes/s   %e ",timeStamp);
                        for(threadId=0; threadId < perfmon_numThreads; threadId++)
                        {
                            printf(" %e  ",1.0E-06*perfmon_getResult(threadId,"PMC0")*64.0/time);
                        }
                        printf("\n");
                    
                        printf("Cache refill bandwidth System  MBytes/s    %e ",timeStamp);
                        for(threadId=0; threadId < perfmon_numThreads; threadId++)
                        {
                            printf(" %e  ",1.0E-06*perfmon_getResult(threadId,"PMC1")*64.0/time);
                        }
                        printf("\n");
                    
            break;
            
        case L2CACHE:

                    
                        printf("L2 request rate   %e ",timeStamp);
                        for(threadId=0; threadId < perfmon_numThreads; threadId++)
                        {
                            printf(" %e  ",(perfmon_getResult(threadId,"PMC1"))/perfmon_getResult(threadId,"PMC0"));
                        }
                        printf("\n");
                    
                        printf("L2 miss rate   %e ",timeStamp);
                        for(threadId=0; threadId < perfmon_numThreads; threadId++)
                        {
                            printf(" %e  ",perfmon_getResult(threadId,"PMC2")/perfmon_getResult(threadId,"PMC0"));
                        }
                        printf("\n");
                    
                        printf("L2 miss ratio   %e ",timeStamp);
                        for(threadId=0; threadId < perfmon_numThreads; threadId++)
                        {
                            printf(" %e  ",perfmon_getResult(threadId,"PMC2")/(perfmon_getResult(threadId,"PMC1")));
                        }
                        printf("\n");
                    
            break;
            
        case L3:

                    
                        printf("Runtime [s]   %e ",timeStamp);
                        for(threadId=0; threadId < perfmon_numThreads; threadId++)
                        {
                            printf(" %e  ",perfmon_getResult(threadId,"PMC2")*inverseClock);
                        }
                        printf("\n");
                    
                        printf("L3 bandwidth [MBytes/s]   %e ",timeStamp);
                        for(threadId=0; threadId < perfmon_numThreads; threadId++)
                        {
                            printf(" %e  ",1.0E-06*(perfmon_getResult(threadId,"PMC0")+perfmon_getResult(threadId,"PMC1"))*64.0/time);
                        }
                        printf("\n");
                    
                        printf("L3 refill bandwidth MBytes/s   %e ",timeStamp);
                        for(threadId=0; threadId < perfmon_numThreads; threadId++)
                        {
                            printf(" %e  ",1.0E-06*perfmon_getResult(threadId,"PMC0")*64.0/time);
                        }
                        printf("\n");
                    
                        printf("L3 evict MBytes/s    %e ",timeStamp);
                        for(threadId=0; threadId < perfmon_numThreads; threadId++)
                        {
                            printf(" %e  ",1.0E-06*perfmon_getResult(threadId,"PMC1")*64.0/time);
                        }
                        printf("\n");
                    
            break;
            
        case MEM:

                    
                        printf("Read data bandwidth (MBytes/s)  %e ",timeStamp);
                        for(threadId=0; threadId < perfmon_numThreads; threadId++)
                        {
                            printf(" %e  ",1.0E-06*perfmon_getResult(threadId,"UPMC0")*64.0/time);
                        }
                        printf("\n");
                    
                        printf("Write data bandwidth (MBytes/s)  %e ",timeStamp);
                        for(threadId=0; threadId < perfmon_numThreads; threadId++)
                        {
                            printf(" %e  ",1.0E-06*perfmon_getResult(threadId,"UPMC0")*8.0/time);
                        }
                        printf("\n");
                    
                        printf("DRAM bandwidth (MBytes/s)   %e ",timeStamp);
                        for(threadId=0; threadId < perfmon_numThreads; threadId++)
                        {
                            printf(" %e  ",1.0E-06*(perfmon_getResult(threadId,"UPMC0"))*64.0/time);
                        }
                        printf("\n");
                    
            break;
            
        case NUMA:

                    
                        printf("Mega requests per second to Node 0   %e ",timeStamp);
                        for(threadId=0; threadId < perfmon_numThreads; threadId++)
                        {
                            printf(" %e  ",1.0E-06*perfmon_getResult(threadId,"PMC0")/time);
                        }
                        printf("\n");
                    
                        printf("Mega requests per second to Node 1   %e ",timeStamp);
                        for(threadId=0; threadId < perfmon_numThreads; threadId++)
                        {
                            printf(" %e  ",1.0E-06*perfmon_getResult(threadId,"PMC1")/time);
                        }
                        printf("\n");
                    
                        printf("Mega requests per second to Node 2   %e ",timeStamp);
                        for(threadId=0; threadId < perfmon_numThreads; threadId++)
                        {
                            printf(" %e  ",1.0E-06*perfmon_getResult(threadId,"PMC2")/time);
                        }
                        printf("\n");
                    
                        printf("Mega requests per second to Node 3   %e ",timeStamp);
                        for(threadId=0; threadId < perfmon_numThreads; threadId++)
                        {
                            printf(" %e  ",1.0E-06*perfmon_getResult(threadId,"PMC3")/time);
                        }
                        printf("\n");
                    
            break;
            

        default:
                fprintf (stderr, "perfmon_printDerivedMetricsinterlagos: Unknown group! Exiting!\n" );
                exit (EXIT_FAILURE);
                break;
    }
}



static PerfmonGroupHelp interlagos_group_help[NUM_GROUPS_INTERLAGOS] = {

    {"BRANCH","Formulas:\n\
Branch rate = BRANCH_RETIRED / INSTRUCTIONS_RETIRED\n\
Branch misprediction rate = BRANCH_MISPREDICT_RETIRED / INSTRUCTIONS_RETIRED\n\
Branch misprediction ratio = BRANCH_MISPREDICT_RETIRED / BRANCH_RETIRED\n\
Branch taken rate = BRANCH_TAKEN_RETIRED / INSTRUCTIONS_RETIRED\n\
Branch taken ratio = BRANCH_TAKEN_RETIRED / BRANCH_RETIRED\n\
Instructions per branch = INSTRUCTIONS_RETIRED / BRANCH_RETIRED\n\
-\n\
The rates state how often in average a branch or a mispredicted branch occured\n\
per instruction retired in total. The Branch misprediction ratio sets directly\n\
into relation what ration of all branch instruction where mispredicted.\n\
Instructions per branch is 1/Branch rate. The same applies for the branches\n\
taken metrics.\n\
\n\
"},

    {"CACHE","Formulas:\n\
Data cache misses = DATA_CACHE_MISSES\n\
Data cache request rate = DATA_CACHE_ACCESSES / INSTRUCTIONS_RETIRED\n\
Data cache miss rate = (DATA_CACHE_REFILLS_VALID)/INSTRUCTIONS_RETIRED\n\
Data cache miss ratio = (DATA_CACHE_REFILLS_VALID)/DATA_CACHE_ACCESSES\n\
-\n\
This group measures the locality of your data accesses with regard to the\n\
L1 Cache. Data cache request rate tells you how data intensive your code is\n\
or how many Data accesses you have in average per instruction.\n\
The Data cache miss rate gives a measure how often it was necessary to get\n\
cachelines from higher levels of the memory hierarchy. And finally \n\
Data cache miss ratio tells you how many of your memory references required\n\
a cacheline to be loaded from a higher level. While the Data cache miss rate \n\
might be given by your algorithm you should try to get Data cache miss ratio\n\
as low as possible by increasing your cache reuse.\n\
\n\
"},

    {"CPI","This group measures how efficient the processor works with\n\
regard to instruction throughput. Also important as a standalone\n\
metric is INSTRUCTIONS_RETIRED as it tells you how many instruction\n\
you need to execute for a task. An optimization might show very\n\
low CPI values but execute many more instruction for it.\n\
\n\
"},

    {"DATA","Formulas:\n\
Load to Store ratio = LS_DISPATCH_LOADS / LS_DISPATCH_STORES\n\
-\n\
This is a simple metric to determine your Load to store ratio.\n\
\n\
"},

    {"FLOPS_DP","Formulas:\n\
DP MFlops/s = 1.0E-06*(RETIRED_FLOPS_DOUBLE_ALL)/time\n\
-\n\
Profiling group to measure double precisision flops.\n\
\n\
\n\
"},

    {"FLOPS_SP","Formulas:\n\
SP MFlops/s = 1.0E-06*(RETIRED_FLOPS_SINGLE_ALL)/time\n\
-\n\
Profiling group to measure single precision flops.\n\
\n\
\n\
"},

    {"FPU_EXCEPTION","Formulas:\n\
Overall FP exception rate = FPU_EXCEPTIONS_ALL / INSTRUCTIONS_RETIRED\n\
FP exception rate = FPU_EXCEPTIONS_ALL / FP_INSTRUCTIONS_RETIRED_ALL\n\
-\n\
Floating point exceptions occur e.g. on the treatment of Denormals.\n\
There might be a large penalty if there are too many floating point\n\
exceptions.\n\
\n\
"},

    {"ICACHE","Formulas:\n\
Instruction cache misses INSTRUCTION_CACHE_L2_REFILLS + INSTRUCTION_CACHE_SYSTEM_REFILLS\n\
Instruction cache request rate INSTRUCTION_CACHE_FETCHES / RETIRED_INSTRUCTIONS\n\
Instruction cache miss rate  (INSTRUCTION_CACHE_L2_REFILLS + INSTRUCTION_CACHE_SYSTEM_REFILLS)/RETIRED_INSTRUCTIONS\n\
Instruction cache miss ratio (INSTRUCTION_CACHE_L2_REFILLS + INSTRUCTION_CACHE_SYSTEM_REFILLS)/INSTRUCTION_CACHE_FETCHES\n\
-\n\
This group measures the locality of your instruction code with regard to the\n\
L1 I-Cache. \n\
\n\
"},

    {"L2","Formulas:\n\
L2 bandwidth MBytes/s   1.0E-06*(DATA_CACHE_REFILLS_ALL-DATA_CACHE_REFILLS_SYSTEM)*64/time\n\
Cache refill bandwidth System/L2 MBytes/s   1.0E-06*DATA_CACHE_REFILLS_ALL*64/time\n\
Cache refill bandwidth System MBytes/s   1.0E-06*DATA_CACHE_REFILLS_SYSTEM*64/time\n\
-\n\
Profiling group to measure L2 cache bandwidth. The bandwidth is\n\
computed by the number of cacheline loaded from L2 to L1 and the\n\
number of modified cachelines evicted from the L1. \n\
Note that this bandwidth also includes data transfers due to a\n\
write allocate load on a store miss in L1 and copy back transfers if\n\
originated from L2.\n\
\n\
"},

    {"L2CACHE","Formulas:\n\
L2 request rate = (L2_REQUESTS_ALL)/INSTRUCTIONS_RETIRED\n\
L2 miss rate  = L2_MISSES_ALL/INSTRUCTIONS_RETIRED\n\
L2 miss ratio = L2_MISSES_ALL/(L2_REQUESTS_ALL)\n\
-\n\
This group measures the locality of your data accesses with regard to the\n\
L2 Cache. L2 request rate tells you how data intensive your code is\n\
or how many Data accesses you have in average per instruction.\n\
The L2 miss rate gives a measure how often it was necessary to get\n\
cachelines from memory. And finally L2 miss ratio tells you how many of your\n\
memory references required a cacheline to be loaded from a higher level.\n\
While the Data cache miss rate might be given by your algorithm you should\n\
try to get Data cache miss ratio as low as possible by increasing your cache reuse.\n\
This group was taken from the whitepaper -Basic Performance Measurements for AMD Athlon 64,\n\
AMD Opteron and AMD Phenom Processors- from Paul J. Drongowski.\n\
\n\
\n\
"},

    {"L3","Formulas:\n\
L3 bandwidth MBytes/s   1.0E-06*(L2_FILL_WB_FILL+L2_FILL_WB_WB)*64/time\n\
L3 refill bandwidth MBytes/s   1.0E-06*L2_FILL_WB_FILL*64/time\n\
-\n\
Profiling group to measure L3 cache bandwidth. The bandwidth is\n\
computed by the number of cacheline loaded from L3 to L2 and the\n\
number of modified cachelines evicted from the L2. \n\
\n\
"},

    {"MEM","Formulas:\n\
Read data bandwidth (MBytes/s)  1.0E-06*NORTHBRIDGE_READ_RESPONSE_ALL*64/time\n\
Write data bandwidth (MBytes/s)  1.0E-06*OCTWORDS_WRITE_TRANSFERS*8/time\n\
Memory bandwidth [MBytes/s] = 1.0E-06*(DRAM_ACCESSES_DCTO_ALL+DRAM_ACCESSES_DCT1_ALL)*64/time\n\
-\n\
Profiling group to measure memory bandwidth drawn by all cores of a socket.\n\
Note: As this group measures the accesses from all cores it only makes sense\n\
to measure with one core per socket, similiar as with the Intel Nehalem Uncore events.\n\
\n\
"},

    {"NUMA","Formulas:\n\
Mega requests per second to Node X   1.0E-06*PMCX/time\n\
-\n\
Profiling group to measure the traffic from local CPU to the different \n\
DRAM NUMA nodes. This group allows to detect NUMA problems in a threaded \n\
code. You must first determine on which memory domains your code is running.\n\
A code should only have significant traffic to its own memory domain.\n\
\n\
\n\
"},

};

