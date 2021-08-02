
(cl:in-package :asdf)

(defsystem "tquad-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "LineSensor" :depends-on ("_package_LineSensor"))
    (:file "_package_LineSensor" :depends-on ("_package"))
  ))