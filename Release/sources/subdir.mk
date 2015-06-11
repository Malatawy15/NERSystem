################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CC_SRCS += \
../sources/data.cc \
../sources/max_entropy_classifier.cc 

OBJS += \
./sources/data.o \
./sources/max_entropy_classifier.o 

CC_DEPS += \
./sources/data.d \
./sources/max_entropy_classifier.d 


# Each subdirectory must supply rules for building sources it contributes
sources/%.o: ../sources/%.cc
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


