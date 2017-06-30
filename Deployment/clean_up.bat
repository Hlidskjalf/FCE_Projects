@echo off


IF EXIST "C:\Documents and Settings\" (
    for /D %%x in ("C:\Documents and Settings\*") do ( 
        rmdir /s /q "%%x\Local Settings\Temporary Internet Files" 
        mkdir "%%x\Local Settings\Temporary Internet Files" 
    )
)

IF EXIST "C:\Documents and Settings\" (
    for /D %%x in ("C:\Documents and Settings\*") do ( 
        rmdir /s /q "%%x\Local Settings\Temp" 
        mkdir "%%x\Local Settings\Temp" 
    )
)

IF EXIST "C:\Users\" (
    for /D %%x in ("C:\Users\*") do ( 
        rmdir /s /q "%%x\AppData\Local\Temp" 
        mkdir "%%x\AppData\Local\Temp" 
    )
)

IF EXIST "C:\Users\" (
    for /D %%x in ("C:\Users\*") do ( 
        rmdir /s /q "%%x\AppData\Local\Microsoft\Windows\Temporary Internet Files" 
        mkdir "%%x\AppData\Local\Microsoft\Windows\Temporary Internet Files" 
    )
)

rd /s /q %systemdrive%\$Recycle.bin