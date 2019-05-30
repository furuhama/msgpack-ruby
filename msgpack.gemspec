$LOAD_PATH.push File.expand_path("../lib", __FILE__)
require 'msgpack/version'

Gem::Specification.new do |s|
  s.name = "msgpack"
  s.version = MessagePack::VERSION
  s.summary = "MessagePack, a binary-based efficient data interchange format."
  s.description = %q{MessagePack is a binary-based efficient object serialization library. It enables to exchange structured objects between many languages like JSON. But unlike JSON, it is very fast and small.}
  s.authors = ["Sadayuki Furuhashi", "Theo Hultberg", "Satoshi Tagomori"]
  s.email = ["frsyuki@gmail.com", "theo@iconara.net", "tagomoris@gmail.com"]
  s.license = "Apache 2.0"
  s.homepage = "http://msgpack.org/"
  s.rubyforge_project = "msgpack"
  s.require_paths = ["lib"]
  s.files = `git ls-files`.split("\n")
  s.extensions = ["ext/msgpack/extconf.rb"]
  s.test_files = `git ls-files -- {test,spec}/*`.split("\n")

  s.add_development_dependency 'bundler'
  s.add_development_dependency 'rake'
  s.add_development_dependency 'rake-compiler', ['~> 1.0']
  # NOTE: rake-compiler-dock SHOULD be updated for new Ruby versions
  s.add_development_dependency 'rake-compiler-dock', ['~> 0.7.0']
  s.add_development_dependency 'rspec', ['~> 3.3']
  s.add_development_dependency 'yard'
  s.add_development_dependency 'json'
end
