taskkill /f /im hl1.exe
taskkill /f /im hl2.exe
taskkill /f /im csgo.exe
taskkill /f /im Steam.exe

REG DELETE HKEY_CURRENT_USER\Software\Valve\Steam\Users /f
REG DELETE HKEY_CURRENT_USER\Software\Valve\Steam\Users /f
REG DELETE HKEY_LOCAL_MACHINE\SOFTWARE\Wow6432Node\Valve\User s /f
REG DELETE HKEY_LOCAL_MACHINE\SOFTWARE\Valve\Users /f
REG DELETE HKEY_CURRENT_USER\Software\Valve\Steam /f
REG DELETE HKEY_CURRENT_USER\Software\Valve /f
REG DELETE HKEY_CURRENT_USER\Software\Wow6432Node\Valve\Steam /f
REG DELETE HKEY_CURRENT_USER\Software\Wow6432Node\Valve /f
REG DELETE HKEY_LOCAL_MACHINE\SOFTWARE\Wow6432Node\Valve\User s /f
REG DELETE HKEY_LOCAL_MACHINE\SOFTWARE\Wow6432Node\Valve /f
REG DELETE HKEY_LOCAL_MACHINE\Software\Valve\Steam\Users /f
REG DELETE HKEY_LOCAL_MACHINE\Software\Valve /f
REG DELETE HKEY_LOCAL_MACHINE\SOFTWARE\Classes\steam /f
REG DELETE HKEY_CURRENT_USER\Software\Classes\steam /f
REG DELETE HKEY_CLASSES_ROOT\steam /f


rmdir /S /Q "C:\Program Files (x86)\Steam\config"

fsutil usn deletejournal /D C:
fsutil usn deletejournal /D D:

ipconfig /flushdns
ipconfig /release
ipconfig /renew

shutdown.exe /r /t 00
exit