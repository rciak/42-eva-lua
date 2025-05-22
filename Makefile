REPONAME:=$(notdir $(CURDIR:/=))

.PHONY: https_autentifcation_to_ssh_autentification
https_autentifcation_to_ssh_autentification:
	@echo 'Before:'
	@git remote -v
	@echo '--------------------------------------------------------------------'
	@echo 'Setting method to ssh autentification:'
	git remote set-url origin git@github.com:rciak/$(REPONAME).git
	@echo '--------------------------------------------------------------------'
	@echo "Now:"
	@git remote -v

