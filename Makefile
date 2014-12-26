NXTOSEK_ROOT = ../../nxtOSEK

TARGET = start_robo

USER_INC_PATH= $(NXTOSEK_ROOT)/ecrobot/nxtway_gs_balancer

USER_LIB = nxtway_gs_balancer

TARGET_SOURCES = start_robo.c

TOPPERS_OSEK_OIL_SOURCE = sample.oil

O_PATH ?= build

include $(NXTOSEK_ROOT)/ecrobot/ecrobot.mak
