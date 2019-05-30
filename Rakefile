
require 'bundler'
Bundler::GemHelper.install_tasks

require 'fileutils'

require 'rspec/core'
require 'rspec/core/rake_task'
require 'yard'

task :spec => :compile

desc 'Run RSpec code examples and measure coverage'
task :coverage do |t|
  ENV['SIMPLE_COV'] = '1'
  Rake::Task["spec"].invoke
end

desc 'Generate YARD document'
YARD::Rake::YardocTask.new(:doc) do |t|
  t.files   = ['lib/msgpack/version.rb','doclib/**/*.rb']
  t.options = []
  t.options << '--debug' << '--verbose' if $trace
end

spec = eval File.read("msgpack.gemspec")

require 'rake/extensiontask'

Rake::ExtensionTask.new('msgpack', spec) do |ext|
  ext.ext_dir = 'ext/msgpack'
  ext.cross_compile = true
  ext.lib_dir = File.join(*['lib', 'msgpack', ENV['FAT_DIR']].compact)
  # cross_platform names are of MRI's platform name
  ext.cross_platform = ['x86-mingw32', 'x64-mingw32']
end

test_pattern = 'spec/{,cruby/}*_spec.rb' # MRI

RSpec::Core::RakeTask.new(:spec) do |t|
  t.rspec_opts = ["-c", "-f progress"]
  t.rspec_opts << "-Ilib"
  t.pattern = test_pattern
  t.verbose = true
end

namespace :build do
  desc 'Build gem for JRuby after cleaning'
  task :java => [:clean, :spec, :build]

  desc 'Build gems for Windows per rake-compiler-dock'
  task :windows do
    require 'rake_compiler_dock'
    # See RUBY_CC_VERSION in https://github.com/rake-compiler/rake-compiler-dock/blob/master/Dockerfile
    RakeCompilerDock.sh 'bundle && gem i json && rake cross native gem RUBY_CC_VERSION=2.2.2:2.3.0:2.4.0:2.5.0:2.6.0'
  end
end

CLEAN.include('lib/msgpack/msgpack.*')

task :default => [:spec, :build, :doc]
