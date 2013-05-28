######################################################################
# Qt Office Charts Library
# Copyright (C) 2013 Łukasz Szewczyk
#
######################################################################

QOC_VER_MAJ      = 0
QOC_VER_MIN      = 0
QOC_VER_PAT      = 1
QOC_VERSION      = $${QOC_VER_MAJ}.$${QOC_VER_MIN}.$${QOC_VER_PAT}


######################################################################
# Install paths
######################################################################

QOC_INSTALL_PREFIX = $$[QT_INSTALL_PREFIX]

unix {
    QOC_INSTALL_PREFIX    = /usr/local/qwt-$$QOC_VERSION-svn
}

win32 {
    QOC_INSTALL_PREFIX    = C:/Qoc-$$QOC_VERSION-svn
}


######################################################################
# Build the static/shared libraries.
# If QocDll is enabled, a shared library is built, otherwise
# it will be a static library.
######################################################################

QOC_CONFIG           += QocDll


