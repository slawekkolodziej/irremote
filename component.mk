# Component makefile for irremote

# include this library as 'irremote/irremote.h'
INC_DIRS += $(irremote_ROOT)..

# args for passing into compile rule generation
irremote_SRC_DIR = $(irremote_ROOT)

$(eval $(call component_compile_rules,irremote))