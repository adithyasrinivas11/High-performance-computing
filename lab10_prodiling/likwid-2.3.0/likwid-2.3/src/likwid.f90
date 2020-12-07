!===========================================================================
!
!     Filename:  likwid.f90
!
!     Description: Marker API f90 module
!
!     Version:  <VERSION>
!     Created:  <DATE>
!
!     Author:  Jan Treibig (jt), jan.treibig@gmail.com
!     Company:  RRZE Erlangen
!     Project:  likwid
!     Copyright:  Copyright (c) 2011, Jan Treibig
!
!     This program is free software; you can redistribute it and/or modify
!     it under the terms of the GNU General Public License, v2, as
!     published by the Free Software Foundation
!    
!     This program is distributed in the hope that it will be useful,
!     but WITHOUT ANY WARRANTY; without even the implied warranty of
!     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
!     GNU General Public License for more details.
!    
!     You should have received a copy of the GNU General Public License
!     along with this program; if not, write to the Free Software
!     Foundation, Inc., 51 Franklin Street, Suite 500, Boston, MA 02110.
!
!===========================================================================



module likwid

interface 

  subroutine likwid_markerInit()
  end subroutine likwid_markerInit

  subroutine likwid_markerClose()
  end subroutine likwid_markerClose

  subroutine likwid_markerStartRegion( regionTag, strLen )
  character(*) :: regionTag
  integer strLen
  end subroutine likwid_markerStartRegion

  subroutine likwid_markerStopRegion( regionTag, strLen )
  character(*) :: regionTag
  integer strLen
  end subroutine likwid_markerStopRegion

end interface

end module likwid

