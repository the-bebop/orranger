#include <alsa/asoundlib.h>
#include <hpp/audio_gen.hpp>
#include <iostream>
#include <stdexcept>

namespace processors {
AudioGenerator::AudioGenerator() {

  if (soundcard.empty()) // use default device
    alsa_error_code =
        snd_pcm_open(&soundDevice, "plughw:0,0", SND_PCM_STREAM_PLAYBACK, 0);
  else // use specified device
    alsa_error_code = snd_pcm_open(&soundDevice, soundcard.c_str(),
                                   SND_PCM_STREAM_PLAYBACK, 0);

  // Check for error on open.
  if (alsa_error_code < 0) {
    std::cout << "[audio_gen:Init] cannot open audio device " << soundcard
              << " (" << snd_strerror(alsa_error_code) << ")" << std::endl;
    throw std::runtime_error("Error");
  }
  std::cout << "[audio_gen:Init] Audio device opened successfully."
            << std::endl;

  // Allocate the hardware parameter structure.
  if ((alsa_error_code = snd_pcm_hw_params_malloc(&hw_params)) < 0) {
    std::cout
        << "[audio_gen:Init] cannot allocate hardware parameter structure ("
        << snd_strerror(alsa_error_code) << ")" << std::endl;
    throw std::runtime_error("Error");
  }

  if ((alsa_error_code = snd_pcm_hw_params_any(soundDevice, hw_params)) < 0) {
    std::cout
        << "[audio_gen:Init] cannot initialize hardware parameter structure ("
        << snd_strerror(alsa_error_code) << ")" << std::endl;
    throw std::runtime_error("Error");
  }

  // Enable resampling.
  unsigned int resample = 1;
  alsa_error_code =
      snd_pcm_hw_params_set_rate_resample(soundDevice, hw_params, resample);
  if (alsa_error_code < 0) {
    std::cout << "[audio_gen:Init] Resampling setup failed for playback: "
              << snd_strerror(alsa_error_code) << std::endl;
    throw std::runtime_error("Error");
  }

  // Set access to RW interleaved.
  if ((alsa_error_code = snd_pcm_hw_params_set_access(
           soundDevice, hw_params, SND_PCM_ACCESS_RW_INTERLEAVED)) < 0) {
    std::cout << "[audio_gen:Init] cannot set access type ("
              << snd_strerror(alsa_error_code) << ")" << std::endl;
    throw std::runtime_error("Error");
  }

  if ((alsa_error_code = snd_pcm_hw_params_set_format(
           soundDevice, hw_params, SND_PCM_FORMAT_S16_LE)) < 0) {
    std::cout << "[audio_gen:Init] cannot set sample format ("
              << snd_strerror(alsa_error_code) << ")" << std::endl;
    throw std::runtime_error("Error");
  }

  // Set channels to stereo (2).
  if ((alsa_error_code =
           snd_pcm_hw_params_set_channels(soundDevice, hw_params, 2)) < 0) {
    std::cout << "[audio_gen:Init] cannot set channel count ("
              << snd_strerror(alsa_error_code) << ")" << std::endl;
    throw std::runtime_error("Error");
  }

  // Set sample rate.
  sampleRate = 44100;
  if ((alsa_error_code = snd_pcm_hw_params_set_rate_near(soundDevice, hw_params,
                                                         &sampleRate, 0)) < 0) {
    std::cout << "[audio_gen:Init] cannot set sample rate to 44100. ("
              << snd_strerror(alsa_error_code) << ")" << std::endl;
    throw std::runtime_error("Error");
  }
  if (sampleRate < 44100) {
    std::cout << "[audio_gen:Init] sample rate does not match requested rate. ("
              << "44100 requested, " << sampleRate << " acquired)" << std::endl;
  }

  // Apply the hardware parameters that we've set.
  if ((alsa_error_code = snd_pcm_hw_params(soundDevice, hw_params)) < 0) {
    std::cout << "[audio_gen:Init] cannot set parameters ("
              << snd_strerror(alsa_error_code) << ")" << std::endl;
    throw std::runtime_error("Error");
  } else {
    std::cout << "[audio_gen:Init] Audio device parameters have been set "
                 "successfully."
              << std::endl;
  }
}
} // namespace processors