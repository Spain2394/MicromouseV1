all:
	echo try: 'make clean', or 'make update'

clean:
	find . -name '*~' -delete
	find . -name '*#' -delete
	find . -name '*.html' -delete # don't put html root

	(cd micromouse-main-board;make clean)

update:
	git add .
	git commit -am "update"
	git push origin master
