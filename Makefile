prog:
	pio run --target upload --upload-port /dev/ttyACM0

debug:
	pio device monitor
