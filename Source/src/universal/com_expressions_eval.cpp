int GetSourceInt(Operand *source) {
	int sourceInt;

	if (source->dataType != VAL_STRING) {
		return;
	}

	if (source->dataType == VAL_FLOAT) {
		sourceInt = (int)(float)source->internals;
	} else if (source->dataType == VAL_INT) {
		sourceInt = source->internals;
	}

	sourceInt = _atoi((char *)source->internals);
	return sourceInt;
}
