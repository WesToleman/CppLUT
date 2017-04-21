CFLAGS = -std=c++11

.DEFAULT_GOAL := all

.PHONY all: LUTColorSpace.o LUTHelper.o LUTColorSpaceWhitePoint.o LUTColor.o

LUT.o: LUT.h LUT.cpp
	cc $(CFLAGS) LUT.cpp -c

LUTColor.o: LUTColor.h LUTColor.cpp LUTHelper.o
	cc $(CFLAGS) LUTColor.cpp -c

LUTColorSpace.o: LUTColorSpace.h LUTColorSpace.cpp LUTColorSpaceWhitePoint.o
	cc $(CFLAGS) LUTColorSpace.cpp -c

LUTColorSpaceWhitePoint.o: LUTColorSpaceWhitePoint.h LUTColorSpaceWhitePoint.cpp #LUTColorTransferFunction.o
	cc $(CFLAGS) LUTColorSpaceWhitePoint.cpp -c

LUTColorTransferFunction.o: LUTColorTransferFunction.o LUTColorTransferFunction.cpp
	cc $(CFLAGS) LUTColorTransferFunction.cpp -c

LUTHelper.o: LUTHelper.h LUTHelper.cpp
	cc $(CFLAGS) LUTHelper.cpp -c

.PHONY clean:
	rm -f *.o