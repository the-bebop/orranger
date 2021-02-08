#ifndef backend_processors_audio_gen_hpp
#define backend_processors_audio_gen_hpp

#include <alsa/asoundlib.h>
#include <string>

namespace processors {

class AudioGenerator {

public:
  AudioGenerator();

private:
  snd_pcm_hw_params_t *hw_params;
  snd_pcm_t *soundDevice;
  std::string soundcard;

  unsigned int alsa_error_code;
  unsigned int sampleRate;
};

} // namespace processors

#endif // backend_processors_audio_gen_hpp