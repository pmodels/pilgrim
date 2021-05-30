#!/bin/bash

make is CLASS=C CLINKFLAGS="-L/g/g90/wang116/softwares/library/ScalaTraceV4/record/lib -lglob -L/g/g90/wang116/softwares/library/ScalaTraceV4/stackwalk/ver0 -lstackwalk"
make lu CLASS=C FMPI_LIB="-L/g/g90/wang116/softwares/library/ScalaTraceV4/record/lib -lglob -L/g/g90/wang116/softwares/library/ScalaTraceV4/stackwalk/ver0 -lstackwalk -lstdc++"
make sp CLASS=C FMPI_LIB="-L/g/g90/wang116/softwares/library/ScalaTraceV4/record/lib -lglob -L/g/g90/wang116/softwares/library/ScalaTraceV4/stackwalk/ver0 -lstackwalk -lstdc++"
make cg CLASS=C FMPI_LIB="-L/g/g90/wang116/softwares/library/ScalaTraceV4/record/lib -lglob -L/g/g90/wang116/softwares/library/ScalaTraceV4/stackwalk/ver0 -lstackwalk -lstdc++"
make mg CLASS=C FMPI_LIB="-L/g/g90/wang116/softwares/library/ScalaTraceV4/record/lib -lglob -L/g/g90/wang116/softwares/library/ScalaTraceV4/stackwalk/ver0 -lstackwalk -lstdc++"
make bt CLASS=C FMPI_LIB="-L/g/g90/wang116/softwares/library/ScalaTraceV4/record/lib -lglob -L/g/g90/wang116/softwares/library/ScalaTraceV4/stackwalk/ver0 -lstackwalk -lstdc++"
make ft CLASS=C FMPI_LIB="-L/g/g90/wang116/softwares/library/ScalaTraceV4/record/lib -lglob -L/g/g90/wang116/softwares/library/ScalaTraceV4/stackwalk/ver0 -lstackwalk -lstdc++"
