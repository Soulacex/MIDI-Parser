################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/hw/printf.c 

OBJS += \
./Core/Src/hw/printf.o 

C_DEPS += \
./Core/Src/hw/printf.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/hw/%.o Core/Src/hw/%.su Core/Src/hw/%.cyclo: ../Core/Src/hw/%.c Core/Src/hw/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L476xx -c -I../Core/Inc/hw -I../Core/Inc -I../Core/Inc/activities -I../Core/Inc/demos -I../Core/Inc/project -I../Core/Inc/system -I../Core/Inc/devices -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-hw

clean-Core-2f-Src-2f-hw:
	-$(RM) ./Core/Src/hw/printf.cyclo ./Core/Src/hw/printf.d ./Core/Src/hw/printf.o ./Core/Src/hw/printf.su

.PHONY: clean-Core-2f-Src-2f-hw

