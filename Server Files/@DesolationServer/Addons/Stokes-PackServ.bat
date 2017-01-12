@echo off
taskkill /f /im arma3.exe
taskkill /f /im arma3server.exe
timeout /t 1
set "mikeroTools=C:\Program Files (x86)\Mikero\DePboTools\bin"
set "modSource=%CD%"
set "deploy=%CD%"
"%mikeroTools%\MakePbo.exe" -@=AdminTools -p -x "thumbs.db,*.txt,*.h,*.dep,*.cpp,*.bak,*.bat,*.png,*.log,*.pew,*.tga" -z "*.wss,*.ogg,*.jpg,*.wav,*.fsm,*.pac,*.paa" "%modSource%\AdminTools" "%deploy%\AdminTools.pbo"
"%mikeroTools%\MakePbo.exe" -@=DesoDB -p -x "thumbs.db,*.txt,*.h,*.dep,*.cpp,*.bak,*.bat,*.png,*.log,*.pew,*.tga" -z "*.wss,*.ogg,*.jpg,*.wav,*.fsm,*.pac,*.paa" "%modSource%\DesoDB" "%deploy%\DesoDB.pbo"
"%mikeroTools%\MakePbo.exe" -@=Desolation -p -x "thumbs.db,*.txt,*.h,*.dep,*.cpp,*.bak,*.bat,*.png,*.log,*.pew,*.tga" -z "*.wss,*.ogg,*.jpg,*.wav,*.fsm,*.pac,*.paa" "%modSource%\Desolation" "%deploy%\Desolation.pbo"
"%mikeroTools%\MakePbo.exe" -@=EarPlugs -p -x "thumbs.db,*.txt,*.h,*.dep,*.cpp,*.bak,*.bat,*.png,*.log,*.pew,*.tga" -z "*.wss,*.ogg,*.jpg,*.wav,*.fsm,*.pac,*.paa" "%modSource%\EarPlugs" "%deploy%\EarPlugs.pbo"
"%mikeroTools%\MakePbo.exe" -@=EasyMode -p -x "thumbs.db,*.txt,*.h,*.dep,*.cpp,*.bak,*.bat,*.png,*.log,*.pew,*.tga" -z "*.wss,*.ogg,*.jpg,*.wav,*.fsm,*.pac,*.paa" "%modSource%\EasyMode" "%deploy%\EasyMode.pbo"
"%mikeroTools%\MakePbo.exe" -@=AntiSideChat -p -x "thumbs.db,*.txt,*.h,*.dep,*.cpp,*.bak,*.bat,*.png,*.log,*.pew,*.tga" -z "*.wss,*.ogg,*.jpg,*.wav,*.fsm,*.pac,*.paa" "%modSource%\AntiSideChat" "%deploy%\AntiSideChat.pbo"
"%mikeroTools%\MakePbo.exe" -@=Jump -p -x "thumbs.db,*.txt,*.h,*.dep,*.cpp,*.bak,*.bat,*.png,*.log,*.pew,*.tga" -z "*.wss,*.ogg,*.jpg,*.wav,*.fsm,*.pac,*.paa" "%modSource%\Jump" "%deploy%\Jump.pbo"
"%mikeroTools%\MakePbo.exe" -@=PluginManager -p -x "thumbs.db,*.txt,*.h,*.dep,*.cpp,*.bak,*.bat,*.png,*.log,*.pew,*.tga" -z "*.wss,*.ogg,*.jpg,*.wav,*.fsm,*.pac,*.paa" "%modSource%\PluginManager" "%deploy%\PluginManager.pbo"
"%mikeroTools%\MakePbo.exe" -@=Realism -p -x "thumbs.db,*.txt,*.h,*.dep,*.cpp,*.bak,*.bat,*.png,*.log,*.pew,*.tga" -z "*.wss,*.ogg,*.jpg,*.wav,*.fsm,*.pac,*.paa" "%modSource%\Realism" "%deploy%\Realism.pbo"
"%mikeroTools%\MakePbo.exe" -@=SpookyWeather -p -x "thumbs.db,*.txt,*.h,*.dep,*.cpp,*.bak,*.bat,*.png,*.log,*.pew,*.tga" -z "*.wss,*.ogg,*.jpg,*.wav,*.fsm,*.pac,*.paa" "%modSource%\SpookyWeather" "%deploy%\SpookyWeather.pbo"
"%mikeroTools%\MakePbo.exe" -@=TimeModify -p -x "thumbs.db,*.txt,*.h,*.dep,*.cpp,*.bak,*.bat,*.png,*.log,*.pew,*.tga" -z "*.wss,*.ogg,*.jpg,*.wav,*.fsm,*.pac,*.paa" "%modSource%\TimeModify" "%deploy%\TimeModify.pbo"
"%mikeroTools%\MakePbo.exe" -@=Zombz -p -x "thumbs.db,*.txt,*.h,*.dep,*.cpp,*.bak,*.bat,*.png,*.log,*.pew,*.tga" -z "*.wss,*.ogg,*.jpg,*.wav,*.fsm,*.pac,*.paa" "%modSource%\Zombz" "%deploy%\Zombz.pbo"
pause
exit /b
