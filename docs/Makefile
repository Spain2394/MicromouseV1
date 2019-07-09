all:
	echo try: 'make clean', or 'make update'

clean:
	find . -name '*~' -delete
	find . -name '*#' -delete

	cd micrmouse-main-board;make clean
update:
	git add .
	git commit -am "update"
	git push origin master
