################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../BehaviourScripts/SceneCamera.cpp 

OBJS += \
./BehaviourScripts/SceneCamera.o 

CPP_DEPS += \
./BehaviourScripts/SceneCamera.d 


# Each subdirectory must supply rules for building sources it contributes
BehaviourScripts/%.o: ../BehaviourScripts/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/include/GL/ -I/usr/include/GL/internal/ -O0 -g3 -Wall -c -fmessage-length=0 -std=gnu++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


