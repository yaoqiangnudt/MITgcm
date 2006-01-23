C $Header: /u/gcmpack/MITgcm/pkg/diagnostics/DIAGSTATS_REGIONS.h,v 1.1 2006/01/23 22:24:28 jmc Exp $
C $Name:  $

CBOP
C     !ROUTINE: DIAGSTATS_REGIONS.h
C     !INTERFACE:
C     include "DIAGSTATS_REGIONS.h"
C     !DESCRIPTION:
C     \bv
C     *==========================================================*
C     | DIAGSTATS_REGIONS.h
C     | o Hold Regions definition variables used for
C     |   regional statistics diagnostics
C     *==========================================================*
C     *==========================================================*
C     \ev
CEOP

C     DIAG_STATS_REGMASK common block:
C     diagSt_regMask :: region mask
C     diagSt_kRegMsk :: region-mask level that identifies the region
C     diagSt_vRegMsk :: region identificator value in the region mask
C     (point i,j belong to region "n" <=> regMask(i,j,kRegMsk(n)) = vRegMsk(n))

#ifdef DIAGSTATS_REGION_MASK
      _RS       diagSt_regMask(1-OLx:sNx+Olx,1-Oly:sNy+Oly,
     &                         sizRegMsk,nSx,nSy)
#else
      _RS       diagSt_regMask(1-Olx:1-Olx,1-Oly:1-Oly,1,nSx,nSy)
c     _RS       diagSt_regMask(1-OLx:sNx+Olx,1-Oly:sNy+Oly,1,nSx,nSy)
#endif /* DIAGSTATS_REGION_MASK */
      _RS       diagSt_vRegMsk(0:nRegions)
      INTEGER   diagSt_kRegMsk(0:nRegions)
      INTEGER   nLevRegMskFile, nLevRegMask
      CHARACTER*(MAX_LEN_FNAM) diagSt_regMaskFile
      COMMON / DIAG_STATS_REGMASK /
     &     diagSt_regMask,
     &     diagSt_vRegMsk,
     &     diagSt_kRegMsk, nLevRegMask,
     &     nLevRegMskFile, diagSt_regMaskFile

C---+----1----+----2----+----3----+----4----+----5----+----6----+----7-|--+----|
