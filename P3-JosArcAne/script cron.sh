#!/bin/bash 


_hoy=$(date +"%m_%d_%Y") 
_archivo="/seguridad/$_hoy" 
mkdir $_archivo
#abrimos la carpeta codigo
cd /codigo
#comprimimos la carpeta codigo
tar czf * codigo.tar
#la copiamos a seguridad dentro de una carpeta
#cuyo nombre corresponde al dia (en formato mes/dia/año)
cp codigo.tar /seguridad/$_hoy
#
# Por si solo esto no funciona
# Ahora debemos hacer lo siguiente:
# chmod 700 copia_seguridad_diaria.sh --> damos permisos
# crontab -e --> abrimos crontab 
# e incluir dentro


