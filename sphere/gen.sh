#!/usr/bin/env bash
set -e
set -x

PATH=$HOME/CLIP.core/msh/ply:$PATH
PATH=$HOME/CLIP.core/msh/vtk:$PATH

dd if=/dev/zero bs=12 count=1 | \
	MSH_LVL=4 ply-pts | \
	tee sphere.ply | \
	ply2vtp sphere.vtp

vtp2raw sphere.vtp sphere-raw
