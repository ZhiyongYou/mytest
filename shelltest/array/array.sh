#!/bin/bash
for skill in 'Ada Coffe Action Java'; do
	SKILL=`echo $skill | awk '{ print $2 }'`
	echo $SKILL
	echo "I am good at ${skill}Script"
done
