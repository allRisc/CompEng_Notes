void covert_channel(char* str) {
  int dummy1;

  // Step through chars
  for (int i = 0; i < strLen(str); i++) {
    // Step through char bits
    for (int j = 0; j < 8; j++) {
      if (bit_set(str[i], j)) {
        // Keep Processor Active
        for (int k=0; k < LOOP_PERIOD; k++)
          dummy1 += dummy1 + 1;
        // Put processor to sleep
        usleep(SLEEP_PERIOD);
      } else {
        // Keep processor asleep
        usleep(SLEEP_PERIOD * 2);
      }
    }
  }
}