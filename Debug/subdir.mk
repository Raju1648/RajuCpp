################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Functionpointer.cpp \
../STL_Vector.cpp \
../Smartpointer.cpp \
../Stack.cpp \
../copy_cons.cpp \
../hello.cpp \
../list.cpp \
../map.cpp \
../set.cpp \
../string.cpp \
../tree.cpp 

OBJS += \
./Functionpointer.o \
./STL_Vector.o \
./Smartpointer.o \
./Stack.o \
./copy_cons.o \
./hello.o \
./list.o \
./map.o \
./set.o \
./string.o \
./tree.o 

CPP_DEPS += \
./Functionpointer.d \
./STL_Vector.d \
./Smartpointer.d \
./Stack.d \
./copy_cons.d \
./hello.d \
./list.d \
./map.d \
./set.d \
./string.d \
./tree.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


