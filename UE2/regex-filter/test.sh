#compile:
g++ -std=c++14 -o regex-filter regex-filter.cpp

./regex-filter "Lu.*@(hpi|student.*).de"
# [leere Ausgabe]

./regex-filter "Lu.*@(hpi|student.*).de" false
# [leere Ausgabe]

./regex-filter "Lu.*@(hpi|student.*).de" true
# hpi: 2
# student.hpi.uni-potsdam: 3

./regex-filter "lu.*@(hpi|student.*).de"
# hpi: 2
# student.hpi.uni-potsdam: 3

./regex-filter hpi.de
# hpi.de: 5

./regex-filter student
# student: 50

./regex-filter "student . hpi . uni-potsdam"
# [leere Ausgabe]

./regex-filter student.hpi.uni-potsdam
# student.hpi.uni-potsdam: 50

./regex-filter "(lu).*@hpi.de"
# lu: 2

./regex-filter "lu.*@hpi.de"
# luge@hpi.de: 1
# lukas.wagner@hpi.de: 1

./regex-filter ".*lu.*@hpi.de"
# lukas.wagner@hpi.de: 1
# norman.kluge@hpi.de: 1

./regex-filter "([a-zA-Z0-9]+).*"
# alison: 1
# anna: 2
# anton: 1
# ben: 2
# christopher: 1
# erik: 1
# fabian: 2
# felix: 1
# finn: 1
# jan: 2
# jasper: 1
# joana: 1
# jonas: 1
# josafat: 1
# josias: 1
# juergen: 1
# julian: 1
# julius: 1
# justus: 2
# kris: 1
# lars: 2
# leon: 3
# leonard: 1
# luc: 1
# lukas: 2
# mark: 1
# markus: 1
# martin: 1
# maximilian: 1
# merlin: 1
# mino: 1
# nico: 1
# norman: 1
# pascal: 1
# paul: 1
# pawel: 1
# petr: 1
# richard: 1
# robin: 1
# simon: 1
# stefan: 1
# sven: 1
# tobias: 2
# valentin: 1
# willy: 1
