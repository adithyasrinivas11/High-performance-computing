#ifndef LIKWID_F90_H
#define LIKWID_F90_H

     use likwid

#define likwid_markerStart(region) \
 likwid_markerStartRegion(region,len_trim(region))

#define likwid_markerStop(region) \
 likwid_markerStopRegion(region,len_trim(region))

#endif
