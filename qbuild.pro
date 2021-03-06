# This is an application
TEMPLATE=app
 
# The binary name
TARGET=qmokoplayer
 
# This app uses Qtopia
CONFIG+=qtopia
DEFINES+=QTOPIA
 
# Build this app as a quicklauncher plugin
# You need to be using the QTOPIA_ADD_APPLICATION/QTOPIA_MAIN macros or this will not work!
#CONFIG+=quicklaunch
 
# Build this project into the singleexec binary
#CONFIG+=singleexec
 
# Specify the languages that make lupdate should produce .ts files for
STRING_LANGUAGE=en_US
LANGUAGES=en_US de
 
# Package information (used for qbuild packages)
pkg [
    name=qmokoplayer
    desc="QMokoPlayer, a multimedia player"
    license=GPLV3
    version=0.3.0-1
    maintainer="Burn2 <info@qtextended.org>"
    domain=window
    devices=ficgta01,neo1973
]
 
# These are the source files that get built to create the application
FORMS=ui/accueil.ui\
	 ui/musicplayer.ui\
	 ui/radioplayer.ui\
	 ui/radioplayeredit.ui\
	 ui/options.ui\
	 ui/youtubeplayer.ui
 
HEADERS=\
    src/accueil.h\
    src/radioplayer.h\
    src/radioplayeredit.h\
    src/options.h\
    src/qmplayer.h\
    src/youtubeplayer.h
 
SOURCES=\
    src/main.cpp\
    src/accueil.cpp\
    src/radioplayer.cpp\
    src/radioplayeredit.cpp\
    src/options.cpp\
    src/qmplayer.cpp\
    src/youtubeplayer.cpp
 
# SXE information
target [
    hint=sxe
    domain=trusted
]
 
# Install the launcher item. The metadata comes from the .desktop file
# and the path here.
desktop [
    hint=desktop nct
    files=qmokoplayer.desktop
    path=/apps/Applications
    trtarget=qmokoplayer-nct
]
 
# Install some pictures.
pics [
    hint=pics
    files=pics/*
    path=/pics/qmokoplayer
]
 
# Install help files
help [
    hint=help
    source=help
    files=example.html
]
 
