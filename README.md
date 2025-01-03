# SMART-FLOWER-POT



If you programing arduino in arduino IDE on Linux you can have this error

"Permission denied Failed uploading: uploading error: exit status 1"

to fix run this

```bash 
sudo chmod a+rw /dev/ttyACM0
```

or

```bash 
sudo chmod a+rw /dev/ttyUSB0
```
