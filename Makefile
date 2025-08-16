# ===============================
# Semantic JSON tooling build
# ===============================

SEMJ_SRC=src/tooling/semjson/hb_semjson.c \
         src/tooling/semjson/hb_semjson_fs.c
SEMJ_HDR=src/tooling/semjson/hb_semjson.h \
         src/tooling/semjson/hb_semjson_schema.h

bin/hb-semjson-dummy: $(SEMJ_SRC) src/tooling/semjson/hb_semjson_dummy.c $(SEMJ_HDR)
	@mkdir -p bin
	$(CC) -O2 -std=c11 -o $@ $^

.PHONY: semantic-json-dummy
semantic-json-dummy: bin/hb-semjson-dummy
	./bin/hb-semjson-dummy --out .harboursems \
	  tests/fixtures/semantic/foo.prg \
	  tests/fixtures/semantic/bar.prg || true
