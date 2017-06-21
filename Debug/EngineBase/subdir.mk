################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../EngineBase/Chunk.cpp \
../EngineBase/Quaternion.cpp \
../EngineBase/essentials.cpp 

OBJS += \
./EngineBase/Chunk.o \
./EngineBase/Quaternion.o \
./EngineBase/essentials.o 

CPP_DEPS += \
./EngineBase/Chunk.d \
./EngineBase/Quaternion.d \
./EngineBase/essentials.d 


# Each subdirectory must supply rules for building sources it contributes
EngineBase/%.o: ../EngineBase/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -std=gnu++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


