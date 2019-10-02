all:
	echo try: 'make clean', or 'make update'

clean:
	#make current dir clean
	find . -name '*~' -delete
	find . -name '*#' -delete
	find . -name '*.html' -delete

	./clean.sh

update:
	# git add .
	# git commit -am "update"
	# git push origin master
