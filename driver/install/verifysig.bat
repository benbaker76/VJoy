@ECHO OFF
Signtool verify /pa /v amd64\vjoy.sys
Signtool verify /pa /v i386\vjoy.sys
Signtool verify /pa /v ia64\vjoy.sys
