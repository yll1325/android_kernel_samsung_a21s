#grip_sensor
obj-$(CONFIG_SENSORS_SX9360)  		+= sx9360.o
obj-$(CONFIG_SENSORS_SX9360_SUB)	+= sx9360_sub.o
obj-$(CONFIG_SENSORS_ISG5320A)		+= isg5320a.o
obj-$(CONFIG_SENSORS_ISG5320A_SUB)	+= isg5320a_sub.o

obj-$(CONFIG_SENSORS_SSP)		+= ssp_platform.o ssp_data.o ssp_comm.o ssp_debug.o ssp_dev.o ssp_sysfs.o sensors_core.o \
					   ssp_iio.o ssp_scontext.o ssp_sensor_dump.o ssp_dump.o ssp_injection.o ssp_firmware.o\
                                           ssp_sensor.o

GCOV_PROFILE := $(CONFIG_KUNIT)

obj-$(CONFIG_SENSORS_SSP)		+= ssp_platform.o 

GCOV_PROFILE := $(CONFIG_KUNIT)
