all:

clean:
	find . -name '*~' -delete
	find . -name '*#' -delete
	find . -name '*.s#[0-9]' -delete

	$(RM) *.s#[0-9]
	$(RM) *.b#[0-9]
	$(RM) *.l#[0-9]
	$(RM) *.job
	$(RM) *.log
	$(RM) *.scr
	$(RM) *.pro
