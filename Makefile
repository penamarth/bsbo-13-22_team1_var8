umlgen:
	plantuml -svg -o ${CURDIR}/assets/plantuml/ ${CURDIR}/use_cases/**.md

clean:
	rm -rf ${CURDIR}/assets/plantuml/*
