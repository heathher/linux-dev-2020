bin_PROGRAMS=main
pkgdata_DATA=ru/LC_MESSAGES/main.mo

ru/LC_MESSAGES/main.mo: ru.po
	mkdir -p `dirname $@`
	msgfmt $< -o $@

ru.po:	messages.pot
	msgmerge -U $@ $<

messages.pot:	main.pot main.c
	xgettext -k_ -c main.c -o messages.new.pot
	cp main.pot messages.pot
	msgmerge -U messages.pot messages.new.pot
