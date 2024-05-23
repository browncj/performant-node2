#include <boost/geometry.hpp>
#include <boost/geometry/geometries/point.hpp>
#include <boost/geometry/srs/spheroid.hpp>
#include <boost/geometry/strategies/geographic/distance.hpp>
#include <iostream>
#include <napi.h>

namespace bg = boost::geometry; // Namespace alias for brevity

// Geographic point type in degrees
typedef bg::model::point<double, 2, bg::cs::geographic<bg::degree>> geo_point;

Napi::Number distanceToLondon(const Napi::CallbackInfo &info) {
  Napi::Env env = info.Env();

  if (info.Length() < 2 || !info[0].IsNumber() || !info[1].IsNumber()) {
    Napi::TypeError::New(env, "Expected two numbers (longitude, latitude)")
        .ThrowAsJavaScriptException();
    return Napi::Number::New(env, NAN);
  }

  const double longitude = info[0].As<Napi::Number>().DoubleValue();
  const double latitude = info[1].As<Napi::Number>().DoubleValue();

  geo_point inputPoint(longitude, latitude);
  geo_point londonPoint(-0.13, 51.5);

  // Calculate distance (Vincenty is the default for geographic)
  double distanceMeters = bg::distance(inputPoint, londonPoint);
  double distanceKilometers = distanceMeters / 1000.0;

  return Napi::Number::New(env, distanceKilometers);
}

Napi::Object Init(Napi::Env env, Napi::Object exports) {
  exports.Set(Napi::String::New(env, "distanceToLondon"),
              Napi::Function::New(env, distanceToLondon));
  return exports;
}

NODE_API_MODULE(addon, Init)
