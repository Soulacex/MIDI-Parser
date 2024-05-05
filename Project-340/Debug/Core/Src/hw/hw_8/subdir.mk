################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/hw/hw_8/hw8.c 

OBJS += \
./Core/Src/hw/hw_8/hw8.o 

C_DEPS += \
./Core/Src/hw/hw_8/hw8.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/hw/hw_8/%.o Core/Src/hw/hw_8/%.su Core/Src/hw/hw_8/%.cyclo: ../Core/Src/hw/hw_8/%.c Core/Src/hw/hw_8/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L476xx -c -I../Core/Inc/hw/hw_3 -I../Core/Inc/hw/hw_8/ -I../Core/Inc/hw/hw_5 -I../Core/Inc/hw -I../Core/Inc/hw/hw_1 -I../Core/Inc -I../Core/Inc/activities -I../Core/Inc/demos -I../Core/Inc/project -I../Core/Inc/system -I../Core/Inc/devices -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -I../Core/Inc/hw/hw_6 -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-hw-2f-hw_8

clean-Core-2f-Src-2f-hw-2f-hw_8:
	-$(RM) ./Core/Src/hw/hw_8/hw8.cyclo ./Core/Src/hw/hw_8/hw8.d ./Core/Src/hw/hw_8/hw8.o ./Core/Src/hw/hw_8/hw8.su

.PHONY: clean-Core-2f-Src-2f-hw-2f-hw_8

