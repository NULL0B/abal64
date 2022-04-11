# ------------------------------------------------------------------------------------
# This makefile is responsible for the production of the new Abal 3 Z Library Package
# its modules, programs and include files, and building the complete tar zipped file.
# ------------------------------------------------------------------------------------
# Both 16 bit and 32 bit translated versions are available
# ------------------------------------------------------------------------------------

# ------------------------------------
# Wabal project to Makefile conversion
# ------------------------------------
zlibrary.mf: zlibrary.jrp
	yabal -h$(ABAL)/zlib/ -iabal3.def $*
! make

# -------------------------
# 32 bit translated version
# -------------------------
otr   = otr32
old   = old32
ao    = ao32
avnor = avnor
tc    = .tc32

! include zlibrary
! make

# -------------------------
# 16 bit translated version
# -------------------------
PATH0 = $(PATH0)abal2/
PATH2 = $(PATH2)abal2/
otr   = otr16
old   = old32
ao    = ao32
avnor = avnor
tc    = .tc16

! include zlibrary
! make

# ----------------
# Pack Preparation
# ----------------
! include zinclude
! make
! include zpackage
! make




