################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/project/handle_functions.c \
../Core/Src/project/manual.c \
../Core/Src/project/midi.c \
../Core/Src/project/project.c \
../Core/Src/project/read_track.c \
../Core/Src/project/song.c \
../Core/Src/project/tone.c \
../Core/Src/project/uint_converters.c 

OBJS += \
./Core/Src/project/handle_functions.o \
./Core/Src/project/manual.o \
./Core/Src/project/midi.o \
./Core/Src/project/project.o \
./Core/Src/project/read_track.o \
./Core/Src/project/song.o \
./Core/Src/project/tone.o \
./Core/Src/project/uint_converters.o 

C_DEPS += \
./Core/Src/project/handle_functions.d \
./Core/Src/project/manual.d \
./Core/Src/project/midi.d \
./Core/Src/project/project.d \
./Core/Src/project/read_track.d \
./Core/Src/project/song.d \
./Core/Src/project/tone.d \
./Core/Src/project/uint_converters.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/project/%.o Core/Src/project/%.su Core/Src/project/%.cyclo: ../Core/Src/project/%.c Core/Src/project/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L476xx -c -I../Core/Inc/hw/hw_3 -I../Core/Inc/hw/hw_8/ -I../Core/Inc/hw/hw_5 -I../Core/Inc/hw -I../Core/Inc/hw/hw_1 -I../Core/Inc -I../Core/Inc/activities -I../Core/Inc/demos -I../Core/Inc/project -I../Core/Inc/system -I../Core/Inc/devices -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -I../Core/Inc/hw/hw_6 -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-project

clean-Core-2f-Src-2f-project:
	-$(RM) ./Core/Src/project/handle_functions.cyclo ./Core/Src/project/handle_functions.d ./Core/Src/project/handle_functions.o ./Core/Src/project/handle_functions.su ./Core/Src/project/manual.cyclo ./Core/Src/project/manual.d ./Core/Src/project/manual.o ./Core/Src/project/manual.su ./Core/Src/project/midi.cyclo ./Core/Src/project/midi.d ./Core/Src/project/midi.o ./Core/Src/project/midi.su ./Core/Src/project/project.cyclo ./Core/Src/project/project.d ./Core/Src/project/project.o ./Core/Src/project/project.su ./Core/Src/project/read_track.cyclo ./Core/Src/project/read_track.d ./Core/Src/project/read_track.o ./Core/Src/project/read_track.su ./Core/Src/project/song.cyclo ./Core/Src/project/song.d ./Core/Src/project/song.o ./Core/Src/project/song.su ./Core/Src/project/tone.cyclo ./Core/Src/project/tone.d ./Core/Src/project/tone.o ./Core/Src/project/tone.su ./Core/Src/project/uint_converters.cyclo ./Core/Src/project/uint_converters.d ./Core/Src/project/uint_converters.o ./Core/Src/project/uint_converters.su

.PHONY: clean-Core-2f-Src-2f-project

