#!/bin/sh

for i in {1..100}
do
    sleep 1 &
done

exec sleep 100
