all:
	echo try: 'make clean', or 'make update'

clean:
	find . -name '*~' -delete
	find . -name '*#' -delete

	(cd projects/MOCI/BAI;make clean)
	(cd projects/MOCI/CORGI;make clean)
	(cd projects/MOCI/MA1404;make clean)
	(cd projects/MOCI/MOCI_CAIB;make clean)
	(cd projects/MOCI/PUSBI;make clean)
	(cd projects/SPOC/SPOC-EGSE; make clean)


	(cd projects/SPOC/Caib;make clean)
	(cd projects/SPOC/EPS-SIM2;make clean)
	(cd projects/SPOC/SPOC_EGSE_SIM;make clean)
	(cd projects/SPOC/SPOC-NANOBED;make clean)
	(cd projects/SPOC/SPOC-EGSE;make clean)

	(cd projects/SPOC/SPOC_EGSE_SIM;make clean)
	(cd projects/SPOC/SPOC-NANOBED;make clean)
	(cd projects/SPOC/SPOC-EGSE;make clean)


	(cd projects/SPOC/SPOC-EGSE/Main\ Board\ Tier\ 2;make clean)
	(cd projects/SPOC/SPOC-EGSE/Main\ Board\ Tier\ 1;make clean)
	(cd projects/SPOC/SPOC-EGSE/LED\ Panel;make clean)
	(cd projects/SPOC/SPOC-EGSE/Switch\ Panel;make clean)


	(cd projects/EE_interviews_2018;make clean)
	(cd projects/Blinky_BJT;make clean)
	(cd projects/EE_interviews_2018;make clean)
	(cd projects/Space-GPU;make clean)
	(cd projects/MOCI/USBC_PATCH;make clean)

update:
	git add .
	git commit -am "update"
	git push origin master
