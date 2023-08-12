@ECHO OFF
certmgr.exe /add Headsoft.cer /s /r localMachine root
certmgr.exe /add Headsoft.cer /s /r localMachine trustedpublisher
