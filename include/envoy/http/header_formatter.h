#pragma once

#include "envoy/common/optref.h"
#include "envoy/config/typed_config.h"

namespace Envoy {
namespace Http {

/**
 * fixfix
 */
class HeaderKeyFormatter {
public:
  virtual ~HeaderKeyFormatter() = default;

  /**
   * fixfix
   */
  virtual std::string format(absl::string_view key) const PURE;
};

using HeaderKeyFormatterPtr = std::unique_ptr<HeaderKeyFormatter>; // fixfix?
using HeaderKeyFormatterOptConstRef = OptRef<const HeaderKeyFormatter>;

/**
 * fixfix
 */
class StatefulHeaderKeyFormatter : public HeaderKeyFormatter {
public:
  /**
   * fixfix
   */
  virtual void onHeaderReceived(absl::string_view key) PURE;
};

using StatefulHeaderKeyFormatterPtr = std::unique_ptr<StatefulHeaderKeyFormatter>;

/**
 * fixfix
 */
class StatefulHeaderKeyFormatterFactory : public Config::TypedFactory {
public:
  ~StatefulHeaderKeyFormatterFactory() override = default;

  virtual StatefulHeaderKeyFormatterPtr
  createCompressorFactoryFromProto(const Protobuf::Message& config) PURE;

  std::string category() const override { return "envoy.http.header_formatter"; }
};

} // namespace Http
} // namespace Envoy