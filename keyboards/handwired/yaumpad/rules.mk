MCU = RP2040
BOOTLOADER = rp2040
LTO_ENABLE = yes			# link time optimization -- achieves a smaller compiled size
IDLE_TIMEOUT_ENABLE = yes
VIA_ENABLE = yes			# via support
TAP_DANCE_ENABLE = no		# tab dance
LEADER_ENABLE = yes			# leader key support
UNICODE_ENABLE = yes		# unicode support
#UNICODEMAP_ENABLE = yes
COMBO_ENABLE = no
WPM_ENABLE = yes  			# Enable word per minute counter
COMMAND_ENABLE = yes
CONSOLE_ENABLE = yes
ENCODER_MAP_ENABLE = yes
ENCODER_ENABLE = yes

# PIO serial/WS2812 drivers must be used on RP2040
SERIAL_DRIVER = vendor
WS2812_DRIVER = vendor

OLED_ENABLE = yes
OLED_DRIVER_ENABLE = yes
OLED_TRANSPORT = i2c

# Audio currently doesn't work with the RP2040
AUDIO_ENABLE = no