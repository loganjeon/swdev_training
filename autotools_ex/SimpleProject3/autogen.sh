#!/bin/sh

glibtoolize --force
aclocal
automake --add-missing --force-missing
autoconf
